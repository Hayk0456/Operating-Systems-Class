#include <stdio.h>
#include <stdlib.h>  


int main()
{   int n;
    int *arr;
    printf("Type a number: \n");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));;
    printf("Array after calloc: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nEnter the array values: ");
    float sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    free(arr);
    printf("Average: %.1f", sum/n);
    return 0;
}
