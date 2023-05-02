#include <stdio.h>
#include <stdlib.h>

int *alocateArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    return array;
}

// find mathing elements in two arrays
int *findMatchingElements(int *array1, int *array2, int size1, int size2) {
    int *matchingElements = alocateArray(size1);
    int index = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
                matchingElements[index] = array1[i];
                index++;
            }
        }
    }
    return matchingElements;
}

int main(){
    int size1, size2;
    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter size of second array: ");
    scanf("%d", &size2);
    int *array1 = alocateArray(size1);
    int *array2 = alocateArray(size2);
    if (array1 == NULL || array2 == NULL) {
        printf("Error");
        return 0;
    }
    for (int i = 0; i < size1; i++) {
        printf("Enter element %d of first array: ", i);
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < size2; i++) {
        printf("Enter element %d of second array: ", i);
        scanf("%d", &array2[i]);
    }
    int *matchingElements = findMatchingElements(array1, array2, size1, size2);
    printf("Matching elements: ");
    for (int i = 0; i < size1; i++) {
        if (matchingElements[i] != 0) {
            printf("%d ", matchingElements[i]);
        }
    }
    return 0;
}

