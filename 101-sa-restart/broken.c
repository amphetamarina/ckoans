#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

volatile sig_atomic_t alarm_fired = 0;

void alarm_handler(int sig) {
    alarm_fired = 1;
}

int main(void) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = alarm_handler;
    sigemptyset(&sa.sa_mask);
    // BUG: Missing SA_RESTART flag - read() will be interrupted
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    printf("Reading from stdin (will be interrupted by alarm)...\n");

    // Set alarm to fire in 1 second
    alarm(1);

    char buffer[128];
    ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (n < 0) {
        if (errno == EINTR) {
            printf("read() was interrupted by signal\n");
            printf("Alarm fired: %d\n", alarm_fired);
            return 1;
        }
        perror("read");
        return 1;
    }

    // This should be reached if SA_RESTART is set
    buffer[n] = '\0';
    printf("Read succeeded: %s", buffer);
    printf("Alarm fired: %d\n", alarm_fired);

    return 0;
}
