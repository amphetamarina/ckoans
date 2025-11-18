#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t signal_count = 0;

void unsafe_handler(int sig) {
    signal_count++;

    // BUG: printf is not async-signal-safe (uses internal buffers)
    printf("Signal received! Count: %d\n", signal_count);

    // BUG: malloc is not async-signal-safe (could corrupt heap)
    char *msg = malloc(32);
    if (msg) {
        snprintf(msg, 32, "Allocated in handler\n");
        free(msg);
    }
}

int main(void) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = unsafe_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    printf("Starting signal test\n");

    // Send signals to ourselves
    for (int i = 0; i < 3; i++) {
        raise(SIGUSR1);
    }

    printf("Signals processed: %d\n", signal_count);
    return 0;
}
