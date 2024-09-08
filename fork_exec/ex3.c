#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int check;
    int ret = fork();

    if (ret == 0) {

        check = execl("/usr/bin/echo", "echo", "Hello from the child process", NULL);
        _exit(1);

    } else {
        printf("Parent Process Ended\n");
    }

    return 0;
}
