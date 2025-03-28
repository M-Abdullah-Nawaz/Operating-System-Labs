// MUhammad Abdullah Nawaz
// i21-1393
// os - Assignment 03

//                                                                  QUESTION 04


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define num 100

int count =0;   //to check for the count
pthread_t mutex;

void *increment(void *args){
for (int i = 0; i < num; i++) {
  pthread_mutex_lock(&mutex);
 count++;
   printf("Count is being incremented  %d\n", count);
 pthread_mutex_unlock(&mutex);
    }
  return NULL;
}

int main(){
  pthread_mutex_init(&mutex, NULL);
 pthread_t td1, td2;
   pthread_create(&td1, NULL,increment, NULL);
 pthread_create(&td2, NULL,increment, NULL);
    pthread_join(td1, NULL);
    pthread_join(td2, NULL);
        pthread_mutex_destroy(&mutex);
return 0;
}
