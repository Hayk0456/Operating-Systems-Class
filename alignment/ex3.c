#include <stdio.h>
#pragma pack(1)
struct PackedStruct {
    char a;
    int b;
    double c;
};
#pragma pack()

int main() {
    struct PackedStruct s;

    printf("Size of struct: %zu bytes\n", sizeof(struct PackedStruct));
    printf("Address of field 'a': %p\n", (void *)&s.a);
    printf("Address of field 'b': %p\n", (void *)&s.b);
    printf("Address of field 'c': %p\n", (void *)&s.c);

    return 0;
}
