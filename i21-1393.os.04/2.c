//i21-1393
// M Abdullah Nawaz
//cs-5c
//os lab 04
//   question 02

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/wait.h>
#include <fcntl.h>
int main(){

    int temp;
    char arr;
    char *buff = "OperatingSystem";
    temp = open("test.txt", O_RDWR | O_CREAT, 0644);
    if (temp == -1){
        perror("open");
        exit(1);
    }
    write(temp, buff, strlen(buff));
    lseek(temp, 1, SEEK_SET);
    while (read(temp, &arr, 1) > 0){
        printf("%c", arr);
        lseek(temp, 2, SEEK_CUR);
    }
    close(temp);
    return 0;
}
