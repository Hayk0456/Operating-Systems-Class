#include <stdio.h>

int main() {
    int num;
    char ch;
    double dbl;
    short sh;

    printf("Size of int: %zu bytes\n", sizeof(num));
    printf("Size of char: %zu byte\n", sizeof(ch));
    printf("Size of double: %zu bytes\n", sizeof(dbl));
    printf("Size of short: %zu bytes\n", sizeof(sh));

    printf("\nAddress of int variable: %p\n", &num);
    printf("Address of char variable: %p\n", &ch);
    printf("Address of double variable: %p\n", &dbl);
    printf("Address of short variable: %p\n", &sh);

    return 0;
}
