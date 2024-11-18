#include <stdio.h>
#include <pthread.h>

void *increment(int integer);

int main()
{
    int shared_int = 0;

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_t thread5;

    pthread_create(&thread1, NULL, increment,)

}