#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum[2] = {0};

void* calculate_sum(void* arg) {
    int thread_id = *(int*)arg;
    int start = thread_id * (ARRAY_SIZE / 2);
    int end = start + (ARRAY_SIZE / 2);

    for (int i = start; i < end; i++) {
        sum[thread_id] += array[i];
    }

    printf("Thread %d: Sum = %d\n", thread_id, sum[thread_id]);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int thread_ids[2] = {0, 1};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculate_sum, &thread_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total Sum = %d\n", sum[0] + sum[1]);
    return 0;
}
