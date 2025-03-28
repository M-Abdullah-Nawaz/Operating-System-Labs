//#include<iostream>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
//using namespace std;
int main(int argc,char*argv[ ]){
char* ptr = argv[1];
printf("array: %s\nsize: %zu\n", ptr,strlen(ptr));

return 0;
}
