#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t sigint_count = 0;

void sigint_handler(int sig) {
    sigint_count++;
}

int main(void) {
    struct sigaction sa;

    // BUG: Forgot to initialize sa with memset or = {0}
    // This leaves random garbage in sa_mask and sa_flags
    sa.sa_handler = sigint_handler;
    // BUG: Should initialize sa_mask with sigemptyset(&sa.sa_mask)
    // BUG: Should set sa.sa_flags = 0 or use specific flags

    if (sigaction(SIGINT, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    printf("Signal handler installed. Sending SIGINT to self...\n");

    // Send SIGINT to ourselves
    raise(SIGINT);
    raise(SIGINT);
    raise(SIGINT);

    printf("Caught %d SIGINT signals\n", sigint_count);

    // Now test ignoring signals
    signal(SIGINT, SIG_IGN);
    printf("SIGINT now ignored. Sending SIGINT...\n");

    raise(SIGINT);
    printf("Signal was ignored (we're still running)\n");

    // Restore default disposition
    signal(SIGINT, SIG_DFL);
    printf("SIGINT restored to default\n");
    printf("Done\n");

    return 0;
}
