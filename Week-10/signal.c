#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signo) {
    // This function will be called when a signal is received
    if (signo == SIGUSR1) {
        printf("Received SIGUSR1 - Suspending the process.\n");
        raise(SIGSTOP);  // Suspend the process
        printf("Resuming the process after suspension.\n");
    }
}

int main() {
    // Register the signal handler function
    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Process ID: %d\n", getpid());
    printf("Send SIGUSR1 signal to suspend and resume this process.\n");

    while (1) {
        // Main loop, keep the program running
        sleep(1);
    }

    return 0;
}

