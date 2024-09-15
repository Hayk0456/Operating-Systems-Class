#include <stdio.h>
int main(){
	int a = 5;
	int *ptr = &a;
	printf("Address of integer: %p\n", &a);
	printf("Address of integer: %p\n", ptr);
	*ptr = 6;
	printf("Value: %d\n", a);

}
