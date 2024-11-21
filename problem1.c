#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 4

int shared_int = 0;
pthread_mutex_t lock;

void *increment(void *arg) {
    pthread_mutex_lock;
    shared_int++;
    pthread_mutex_unlock;
    }

int main() {

    pthread_t threads[NUM_THREADS];
    int rc;

    pthread_mutex_init(&lock, NULL);


    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, &increment, NULL);
        if (rc != 0){
            printf("error\n");
            exit(1);
            }
        else {
            printf("Thread created successfully\n");

        }
        printf("Shared int is: %d\n", shared_int);
    }

    for (int i=0; i< NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value for shared int is: %d\n", shared_int);

    pthread_mutex_destroy(&lock);
    exit(0);

}