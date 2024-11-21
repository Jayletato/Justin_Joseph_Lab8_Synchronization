#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 1

int fibonacci(int num) {
  if (num <= 1 ) {
  
    return num;
  }
  else {
    return fibonacci(num-1)+fibonacci(num-2);
  }
}

long * fibSequence;
long num;
pthread_mutex_t lock;

void *fibonacciArray(void *arg) {
  pthread_mutex_lock(&lock);

  long * fibArray = (long*)malloc(num * sizeof(long));
  if (fibSequence == NULL) {
    exit(1);
    }

  for (int i = 0; i < num; i++) {
    fibSequence[i] = fibonacci(i);
    }
  
  pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[]) {

  pthread_t threads[NUM_THREADS];
  pthread_mutex_init(&lock, NULL);

  if (argc != 2) {
    printf("This program only takes one argument!\n");
    exit(1);
  }
  char *p;
  num = strtol(argv[1], &p, 10);

  for (int i = 0; i < NUM_THREADS; i++){
    pthread_create(&threads[i], NULL, fibonacciArray, NULL);
  }

  for (int i = 0; i < num; i++) {
    printf("%ld ", fibSequence[i]);
  }

  printf("\n");

  for (int i = 0; i < NUM_THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&lock);
  free(fibSequence);
}
