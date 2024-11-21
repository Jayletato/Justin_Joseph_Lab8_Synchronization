#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *increment(void *integer) {
    integer++;
    }

int main() {
    int *shared_int = 0;

    pthread_t threads[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, &increment, &shared_int);
        if (rc != 0){
            printf("error\n");
            exit(1);
            }
        else {
            printf("Thread created successfully\n");

        }
        printf("Shared int is: %d\n", *shared_int);
    }

    //printf("Final value for shared int is: %d\n", *shared_int);
    exit(0);

}