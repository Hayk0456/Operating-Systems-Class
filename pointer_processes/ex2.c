#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    printf("Modified: ");

        for (int i = 0; i < size; i++) {
        *(ptr + i) += 1;
        printf("%d ", *(ptr + i));

    }
    printf("\n");
    printf("Modified array using array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
