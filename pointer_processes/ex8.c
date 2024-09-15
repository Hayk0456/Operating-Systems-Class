#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status1, status2;
    
    pid1 = fork();
    
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed for the first child process.\n");
        exit(1);
    } else if (pid1 == 0) {
        printf("First child process (PID: %d) exiting with status 2.\n", getpid());
        exit(2);
    }
    
    pid2 = fork();
    
    if (pid2 < 0) {
        fprintf(stderr, "Fork failed for the second child process.\n");
        exit(1);
    } else if (pid2 == 0) {
        printf("Second child process (PID: %d) exiting with status 3.\n", getpid());
        exit(3);
    }
    
    waitpid(pid1, &status1, 0);
    
    if (WIFEXITED(status1)) {
        printf("First child process (PID: %d) exited normally with status: %d\n", pid1, WEXITSTATUS(status1));
    } else {
        printf("First child process (PID: %d) exited abnormally.\n", pid1);
    }
    
    waitpid(pid2, &status2, 0);
    
    if (WIFEXITED(status2)) {
        printf("Second child process (PID: %d) exited normally with status: %d\n", pid2, WEXITSTATUS(status2));
    } else {
        printf("Second child process (PID: %d) exited abnormally.\n", pid2);
    }
    
    return 0;
}
