// MUhammad Abdullah Nawaz
// i21-1393
// os - Assignment 03

//                                                                  QUESTION 03



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include<string.h>

sem_t sem_a, sem_b, sem_c;
void *generate_a(void *arg) {
    for (int i = 0; i < 1; i++) {
        printf("a");                // first printig a 
        sem_post(&sem_c);   //  then signal the c generator semaphore and b is in wait
    }
    return NULL;
}

void *generate_b(void *arg) {
    for (int i = 0; i < 1; i++) {
        sem_wait(&sem_b);    // then printing the B and signal the A semaphore bez after b again a
        printf("b");
        sem_post(&sem_a);
    }
    return NULL;
}

void *generate_c(void *arg) {
    for (int i = 0; i < 1; i++) {
        sem_wait(&sem_c);
        printf("c");
        sem_post(&sem_b);            // print c and then signal the B semaphore
    }
    return NULL;
}

int main() {
    sem_init(&sem_a, 0, 1);
    sem_init(&sem_b, 0, 0);
    sem_init(&sem_c, 0, 0);

    char input[] = "aaacbaaacbaaacb";
for(int i=0;i<=10;i++){
    for (int i = 0; i <10; i++) {
       switch (input[i]) {
          case 'a':
           generate_a(NULL);
           break;
          case 'b':
           generate_b(NULL);
           break;
          case 'c':
           generate_c(NULL);
           break;
        }
    }
}
    sem_destroy(&sem_a);
    sem_destroy(&sem_b);
    sem_destroy(&sem_c);

    return 0;
}

