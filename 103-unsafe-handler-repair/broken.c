#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t signal_count = 0;

void signal_handler(int sig) {
    signal_count++;

    // BUG: sprintf is NOT async-signal-safe
    char buffer[64];
    sprintf(buffer, "Caught signal #%d\n", signal_count);

    // BUG: printf is NOT async-signal-safe
    printf("%s", buffer);

    // BUG: strlen is often safe but not guaranteed; use literal length
    // BUG: Should use write() with string literal instead
}

int main(void) {
    struct sigaction sa;

    // BUG: Not initializing sa - contains garbage
    sa.sa_handler = signal_handler;
    // BUG: Not calling sigemptyset(&sa.sa_mask)
    // BUG: Not setting sa.sa_flags (should set to 0 or SA_RESTART)

    if (sigaction(SIGUSR1, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    printf("Sending 3 signals...\n");

    raise(SIGUSR1);
    raise(SIGUSR1);
    raise(SIGUSR1);

    // Small delay to ensure signals are processed
    usleep(100000);

    printf("Total signals caught: %d\n", signal_count);
    return 0;
}
