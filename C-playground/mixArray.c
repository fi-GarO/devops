#include <stdio.h>
#include <stdlib.h>

int *alocateArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    return array;
}

// mix array
int *mixArray(int *array, int size) {
    int *mixedArray = alocateArray(size);
    for (int i = 0; i < size; i++) {
        mixedArray[i] = array[i];
    }
    for (int i = 0; i < size; i++) {
        int randomIndex = rand() % size;
        int temp = mixedArray[i];
        mixedArray[i] = mixedArray[randomIndex];
        mixedArray[randomIndex] = temp;
    }
    return mixedArray;
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
    int *mixedArray = mixArray(array, size);
    printf("Mixed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", mixedArray[i]);
    }
    return 0;
}