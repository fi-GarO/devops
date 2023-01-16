#include <stdio.h>
#include <stdlib.h>

int *alocateArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    return array;
}

// find even numbers in array
int *findEvens(int *array, int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            index++;
        }
    }
    int *evens = alocateArray(index);
    index = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            evens[index] = array[i];
            index++;
        }
    }
    return evens;
}

int main(){
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
    int *evens = findEvens(array, size);
    printf("Even numbers: ");
    for (int i = 0; i < size; i++) {
        if (evens[i] != 0) {
            printf("%d ", evens[i]);
        }
    }
    return 0;
}