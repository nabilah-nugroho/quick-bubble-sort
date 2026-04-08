#include <stdio.h>

//bubble sort
void bubble_sort(int array[], int size){
    int temp, i, j;
    for (i=0; i<size-1; i++){
        for(j=0; j<size-1-i; j++){
            if (array[j] > array[j+1]){
                temp= array[j]; array[j]=
                array[j+1];array[j+1]= temp;
            }
        }
    }

}
