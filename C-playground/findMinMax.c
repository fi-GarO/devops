// Created by:  blu (4/12/2019 9:00:00 PM)
// Compiler:  TDM-GCC 4.9.2 64-bit Release

#include <stdio.h>
#include <stdlib.h>

int *alocateArray(int size) {
    if (size % 2 != 0) {
        return NULL;
    }
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    return array;
}

// return min and max in array  
int *findMinAndMax(int *array1, int size){
    int min = array1[0];
    int max = array1[0];
    int *minAndMax = alocateArray(2);
    for (int i = 0; i < size; i++) {
        if (array1[i] < min) {
            min = array1[i];
        }
        if (array1[i] > max) {
            max = array1[i];
        }
    }
    minAndMax[0] = min;
    minAndMax[1] = max;
    return minAndMax;
}

int main() { 
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int *array = alocateArray(size);
    if (array == NULL) {
        printf("Error");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &array[i]);
    }
    int *results = findMinAndMax(array, size);
    int min = results[0];
    int max = results[1];
    printf("Min: %d Max: %d", min, max);

    return 0; 
}