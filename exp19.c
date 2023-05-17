#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data = 5; 
sem_t mutex; 

void *thread1(void *arg) {
    int data;
    sem_wait(&mutex); 
    data = shared_data;
    shared_data = data * 2;
    sem_post(&mutex); 
    printf("Thread 1: Doubled data = %d\n", shared_data);
    return NULL;
}

void *thread2(void *arg) {
    int data;
    sem_wait(&mutex); 
    data = shared_data;
    sem_post(&mutex);
    printf("Thread 2: Five times data = %d\n", data * 5);
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    sem_init(&mutex, 0, 1);

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&mutex); 

    return 0;
}
