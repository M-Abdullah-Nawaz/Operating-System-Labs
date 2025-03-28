// MUhammad Abdullah Nawaz
// i21-1393
// os - Assignment 03

//                                                                  QUESTION 6


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define n 5   // 5 philosphers in the soltion

pthread_t philosopher_t[n];
sem_t forkn[n];
sem_t mutex;

void *philosopher(void *arg) {


    int id = *((int *)arg);    
    int right = (id + 1) % n;
    int left = id;
while (1) {
     printf("Philosopher %d is thinking\n", id);  // philospher thinks which to pich 
  sleep(1);

     sem_wait(&mutex);     // initially mutex 1 so after having 1 philospher this will 0 the mutex
   sem_wait(&forkn[left]);      // pick a fork of left on wait after picking
printf("philosopher %d pick the fork  on %d left side \n", id, left);
  sleep(1);
    sem_wait(&forkn[right]);   // if he picks right one then wait right one so no one can pick it 
     printf("philosopher %d pick the fork on %d right side\n", id, right);
      sem_post(&mutex);                           // now anyother philospher can come and pick
printf("philosopher  %d  is  eating  now \n", id);
  sleep(2);

   sem_post(&forkn[left]);                        //    now previous philospher is eating and we will signal that fork which he has pick either left/right so he releases and other can pick
printf("philosopher %d release the fork of %d left side \n", id, left);
   sem_post(&forkn[right]);             // signal 
printf("philosopher %d release the fork of %d right side \n", id, right);
    }
}

int main() {
    int i, id[n];
    sem_init(&mutex, 0, 1);
  for (i = 0; i < n; i++) {
        sem_init(&forkn[i], 0, 1);
}
 for (i = 0; i < n; i++) {
       id[i] = i;
     pthread_create(&philosopher_t[i], NULL, philosopher, &id[i]);      // thread create accourding to number of philosphers
    }
  for (i = 0; i < n; i++) {
     pthread_join(philosopher_t[i], NULL);
    }

    return 0;
}

