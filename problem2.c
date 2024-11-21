#include <stdio.h>
#include <stdlib.h>


int fibonacci(int num) {
  if (num <= 1 ) {
  
    return num;
  }
  else {
    return fibonacci(num-1)+fibonacci(num-2);
  }
}

long * fibSequence;

long *fibonacciArray(long num) {
  long *fibArray = (long*)malloc(num * sizeof(long));
  if (fibArray == NULL) {
    exit(1);
    }

  for (int i = 0; i < num; i++) {
    fibArray[i] = fibonacci(i);
    }

  return fibArray;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("This program only takes one argument!\n");
    exit(1);
  }
  char *p;
  long num = strtol(argv[1], &p, 10);
  
  fibSequence = fibonacciArray(num);

  for (int i = 0; i < num; i++) {
    printf("%ld ", fibSequence[i]);
    }
  printf("\n");

  free(fibSequence);
}
