//i21-1393
// M Abdullah Nawaz
//cs-5c
//os lab 04

//#include<iostream>



#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
//using namespace std;
int main(int argc,char*argv[]){
char* ptr = argv[1];
pid_t p;
p = fork(); 
 
if(p>0){                             
wait(NULL);
p= fork();
if(p>0){
wait(NULL);
printf("programm exected successully in the folk process/n");
}
else if(p == 0){
printf("pid of second process is  given here = %d\n", getgid());
}
}
else if(p==0){
printf("pid of second process 2nd child process = %d\n", getgid());
printf("array: %s\nsize: %zu\n", ptr,strlen(ptr));

printf("calling the next file for the ignorence of the special characters  /n");
execv(" ./1b" ,argv);
}

return 0;
}


