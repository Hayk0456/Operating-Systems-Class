#include <stdio.h>
#include <stdlib.h>


int main()
{	
    char **array = malloc(3 * sizeof(char *));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int i;
    for (i = 0; i < 3; ++i) {
        array[i] = (char *)malloc(31*sizeof(char));
    }
    
    printf("Enter 3 strings :\n");
    for (i = 0; i < 3; i++) {
        printf("String %d: ", i + 1);
        fgets(array[i], 30 + 1, stdin);
    }

    array = (char **)realloc(array, 5 * sizeof(char *));
    for (i = 3; i < 5; ++i) {
        array[i] = (char *)malloc(31*sizeof(char));
    }
    
    printf("\nEnter 2 more strings :\n");
    for (i = 3; i < 5; i++) {
        printf("String %d: ", i + 1);
        fgets(array[i], 30 + 1, stdin);
    }
    for (i = 0; i < 5; i++) {
        printf("String %d: %s", i + 1, array[i]);
    }
    free(array);
}
