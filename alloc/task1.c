#include <stdio.h>
#include <stdlib.h>  


int main()
{   int n;
    int *arr;
    printf("Type a number: \n");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the array values: \n");
    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    free(arr);

    printf("Sum: %d", sum);
    return 0;
}
