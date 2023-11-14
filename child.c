#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID: %d)\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d), Child PID: %d\n", getpid(), pid);
    }

    return 0;
}

