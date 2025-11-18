#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t got_signal = 0;

void safe_handler(int sig) {
    got_signal = 1;

    // BUG: printf is NOT async-signal-safe
    printf("Signal received!\n");

    // This is the safe way to print from a signal handler:
    // const char msg[] = "Signal received!\n";
    // write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

int main(void) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = safe_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    printf("Main: sending signal\n");
    raise(SIGUSR1);

    // Give handler time to run
    sleep(1);

    printf("Main: signal handled = %d\n", got_signal);
    printf("Main: done\n");

    return 0;
}
