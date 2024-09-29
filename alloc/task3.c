#include <stdio.h>
#include <stdlib.h>


int main()
{	int n = 10;
	int *arr;

	arr = (int *)malloc(n * sizeof(int));

	printf("\nEnter the array values: ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int *new_arr = (int *)realloc(arr, 5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}
