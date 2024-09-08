#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int check;
    int ret = fork();

    if (ret == 0) {

        int ret1 = fork();
	if(ret1 == 0)
		execl("/usr/bin/date", "date", NULL);
	else{
		execl("/usr/bin/ls", "ls", "-la", NULL);
	}

    }

    else {
        printf("Parent Process Ended");
    }

    return 0;
}
