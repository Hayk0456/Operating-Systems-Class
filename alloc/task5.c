#include <stdio.h>
#include <stdlib.h>


int main()
{   int n;
    int *arr;
    printf("Enter the number of students: \n");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the grades: \n");
    int highest = 0;
    int lowest = 101;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > highest){
            highest = arr[i];
        }
        if(arr[i] < lowest){
            lowest = arr[i];
        }
        
    }
    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);
    free(arr);
    return 0;
}
