#include <stdio.h>
#include <stdlib.h>

void function1() {
    printf("Function 1 called.\n");
}

void function2() {
    printf("Function 2 called.\n");
}

int main() {
    atexit(function1);
    atexit(function2);
    
    printf("Program starting.\n");
    printf("Program terminating.\n");
    
    return 0;
}
