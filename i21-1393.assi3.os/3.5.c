// MUhammad Abdullah Nawaz
// i21-1393
// os - Assignment 03

//                                                                  QUESTION 05


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define transaction_n 5
#define t_num 3
#define t_amount 200
#define intial_balance 1000
sem_t semaphore;
int acc_balance = intial_balance;

void* transaction(void* id){
 int tid = *(int*)id;
for(int i=0;i<transaction_n;i++){
sem_wait(&semaphore);
acc_balance = acc_balance-t_amount;
   printf("Thread %c withdrew $%d (updated  balance is  $%d)\n", 'A' + tid, t_amount, acc_balance);
sem_post(&semaphore);
}

 pthread_exit(NULL);

}

int main(){
pthread_t thread[t_num];
  int id[t_num] = {0, 1, 2};
   sem_init(&semaphore, 0, 1);

 for (int i = 0; i<t_num; i++){
 pthread_create(&thread[i], NULL,transaction, &id[i]);
    }
 for (int i = 0; i<t_num; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("final balance is $%d\n", acc_balance);

    sem_destroy(&semaphore);
return 0;
}
