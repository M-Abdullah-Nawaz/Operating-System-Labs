// i21-1393
// M Abdullah Nawaz



#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// printing in the ascending
void ascending_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("ascending order \n");
    for(int i=0;i<size;i++){
    printf("%d",array[i]);
}
}

// printing in the descending
void descending_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("descending order \n");
     for(int i=0;i<size;i++){
    printf("%d",array[i]);
}
} 

// finding the highest at nth 
 int get_nth_highest(int *array, int size, int n) {
    return array[size - n];
}
