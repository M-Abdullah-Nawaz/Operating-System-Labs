// MUhammad Abdullah Nawaz
// i21-1393
// os - Assignment 03

//                                                                  QUESTION 01


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define num 10
sem_t semaphore;
pthread_t thread[num];
int fictorials[num];

// intialize the number of threads and semaphore which will be used in main and function as weell

// calculating fictorial
void *find_fictorial(void *args){
 int fictorial = 1;
   int id = *(int *)args;
    int n = id + 1;
   for(int i=1;i<=n;i++){
   fictorial=fictorial*i;
   }
   sem_wait(&semaphore);
      printf("Thread nmber is %d: %d\n", id+1, fictorial);
    fflush(stdout);
sem_post(&semaphore);
fictorials[id] = fictorial;
// condition if the number to find fict is < thread number then create thread of n(number to find fictorial)
   if (n < num) {
        pthread_create(&thread[n], NULL, find_fictorial, &n);
        pthread_join(thread[n], NULL);
    }

    pthread_exit(NULL);

}

int main(){
sem_init(&semaphore,0,1);           // intialize semaphore as a binary semaphore 
int thread_args[num];               // to wait and signal   
thread_args[0]= 0;
pthread_create(&thread,NULL,find_fictorial,&thread_args[0]);               //thread creattion
pthread_join(thread[0],NULL);
sem_destroy(&semaphore);

return 0;
}


