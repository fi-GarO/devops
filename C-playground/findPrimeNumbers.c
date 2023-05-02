#include <stdio.h>
#include <stdlib.h>

int *alocateArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    return array;
}

// find prime numbers in array
int *findPrimeNumbers(int *array, int size) {
    int *primeNumbers = alocateArray(size);
    int index = 0;
    for (int i = 0; i < size; i++) {
        int isPrime = 1;
        for (int j = 2; j < array[i]; j++) {
            if (array[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            primeNumbers[index] = array[i];
            index++;
        }
    }
    return primeNumbers;
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
    int *primeNumbers = findPrimeNumbers(array, size);
    printf("Prime numbers: ");
    for (int i = 0; i < size; i++) {
        if (primeNumbers[i] != 0) {
            printf("%d ", primeNumbers[i]);
        }
    }
    return 0;
}