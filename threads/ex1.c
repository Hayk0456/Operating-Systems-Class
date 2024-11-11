#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    long thread_id = (long)arg;
    printf("Thread %ld is running\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    long i;

    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed\n");
    return 0;
}
