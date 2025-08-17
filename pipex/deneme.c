#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("I am the child process. PID: %d\n", getpid());
    } else {
        // Parent process
        printf("I am the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}

