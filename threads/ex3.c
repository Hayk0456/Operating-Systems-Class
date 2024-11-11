#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* arg) {
    long thread_id = (long)arg;

    for (int i = 1; i <= 5; i++) {
        printf("Thread %ld: %d\n", thread_id, i);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    long thread_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_numbers, (void*)thread_ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
