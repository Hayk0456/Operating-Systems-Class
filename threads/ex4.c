#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 5

int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5};

void* calculate_square(void* arg) {
    int index = *(int*)arg;
    int number = numbers[index];
    int square = number * number;

    printf("Square of %d is %d\n", number, square);

    free(arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int* index = malloc(sizeof(int));
        *index = i;
        pthread_create(&threads[i], NULL, calculate_square, index);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
