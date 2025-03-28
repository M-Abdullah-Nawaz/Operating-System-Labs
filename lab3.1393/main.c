#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main(int argc, char *argv[]) {
  
    int *array = (int *)malloc(sizeof(int) * (argc - 3));
    for (int i = 1; i < argc - 3; i++) {
        array[i - 1] = atoi(argv[i]);
    }
    int order = atoi(argv[argc - 2]);
    int n = atoi(argv[argc - 1]);
    
 
    // Sort the array in the specified order
    if (order == 1) {
        ascending_sort(array, argc - 3);
    } else {
        descending_sort(array, argc - 3);
    }
    // Print the nth highest number from the array
    
     printf("the highest in the array at the nth is\n");
    printf("%d\n", get_nth_highest(array, argc - 3, n));
    
    
    
      // printing the main array elements
    printf("the array elements are: \n");
for(int i=0;i<argc-3;i++){
printf("%d",array[i]);
}

    
    
    return 0;
}
