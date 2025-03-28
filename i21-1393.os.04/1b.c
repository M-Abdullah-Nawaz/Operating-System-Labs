//#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
//#include<stdlib.h>
//using namespace std;
int main(int argc,char*argv[]){
char *ptr = argv[1];
char ptr_new[50];

int i=0,j=0;
for(;i<strlen(ptr);i++){
if((ptr[i]>='a' && ptr[i]<='z' ) || (ptr[i]>='A' && ptr[i]<='Z') || (ptr[i]>='0' && ptr[i]<='9')){
ptr_new[j]=ptr[i];
j++;
}
}

ptr_new[j] ='\0';
argv[1]  =  ptr_new;
execv("./1" ,argv);

return 0;
}
