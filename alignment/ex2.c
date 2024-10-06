#include <stdio.h>

struct MyStruct {
    char a;
    double c;
    int b;
    
};

int main() {
    struct MyStruct s;

    printf("Size of struct: %zu bytes\n", sizeof(struct MyStruct));
    printf("Address of field 'a': %p\n", (void *)&s.a);
    printf("Address of field 'b': %p\n", (void *)&s.b);
    printf("Address of field 'c': %p\n", (void *)&s.c);

    return 0;
}
