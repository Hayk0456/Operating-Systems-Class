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
        exit(2);
    }
    
    pid2 = fork();
    
    if (pid2 < 0) {
        fprintf(stderr, "Fork failed for the second child process.\n");
        exit(1);
    } else if (pid2 == 0) {
        exit(3);
    }
    
    waitpid(pid2, &status2, 0);
    printf("Second child process (PID: %d) finished with exit status: %d\n", pid2, WEXITSTATUS(status2));
    
    wait(&status1);
    printf("First child process (PID: %d) finished with exit status: %d\n", pid1, WEXITSTATUS(status1));
    
    return 0;
}
