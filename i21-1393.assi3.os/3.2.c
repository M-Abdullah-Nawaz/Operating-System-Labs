// MUhammad Abdullah Nawaz
// i21-1393
// os - Assignment 03

//                                                                  QUESTION 02



#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define b_size 1
#define maximum 100

sem_t empty, full, mutex;
int buffer[b_size];
int next_in = 0, next_out = 0;

void *producer(void *arg) {
    for (int i = 1; i <= maximum; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);        
        buffer[next_in] = i;
        next_in = (next_in + 1) % b_size;
        sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    for (int i = 1; i <= maximum; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        
        int item = buffer[next_out];
        next_out = (next_out + 1) % b_size;
        
        sem_post(&mutex);
        sem_post(&empty);
        
        printf("Consumer value is    %d\n", item);
        fflush(stdout);
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&empty, 0, b_size);  // empty with buffer size
    sem_init(&full, 0, 0);   // intialize full with 0
    sem_init(&mutex, 0, 1);    // intialize mutex with 1

    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}

