#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        printf("Child process (PID: %d) exiting.\n", getpid());
        exit(0);
    }
    
    wait(NULL);
    
    printf("Parent process (PID: %d) continuing.\n", getpid());
    sleep(10);
    return 0;
}
