#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;
    int **dptr = &ptr;

    printf("Value of num using pointer: %d\n", *ptr);
    printf("Value of num using double-pointer: %d\n", **dptr);

    return 0;
}
