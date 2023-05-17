#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (i + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS
#define RIGHT (i + 1) % NUM_PHILOSOPHERS
sem_t mutex;
sem_t forks[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];
void *philosopher(void *arg)
{
    int i = *(int *)arg;
    while (1)
    {
        printf("Philosopher %d is thinking\n", i);
        sleep(2);
        take_forks(i);
        printf("Philosopher %d is eating\n", i);
        sleep(2);
        put_forks(i);
    }
}
void take_forks(int i)
{
    sem_wait(&mutex);
    state[i] = HUNGRY;
    test(i);
    sem_post(&mutex);
    sem_wait(&forks[i]);
}
void put_forks(int i)
{
    sem_wait(&mutex);
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}
void test(int i)
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[i] = EATING;
        sem_post(&forks[i]);
    }
}
int main()
{
    int i;
    pthread_t philosophers[NUM_PHILOSOPHERS];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        sem_init(&forks[i], 0, 0);
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&philosophers[i], NULL, philosopher, arg);
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_join(philosophers[i], NULL);
    return 0;
}
