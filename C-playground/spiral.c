#include <stdio.h>
#include <stdlib.h>

// alocate array in a shape of a square
int **alocateSquareArray(int size) {
    int **array = (int **)malloc(size * sizeof(int *));
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        array[i] = (int *)malloc(size * sizeof(int));
        if (array[i] == NULL) {
            return NULL;
        }
    }
    return array;
}

// alocate array of shape square and fill it with numbers with value from 1 to size in a format:
// 1 2 3
// 8 9 4
// 7 6 5
int **fillSpiral(int size) {
    int **array = alocateSquareArray(size);
    if (array == NULL) {
        return NULL;
    }
    int row = 0;
    int column = 0;
    int direction = 0;
    int index = 1;
    while (index <= size * size) {
        array[row][column] = index;
        index++;
        if (direction == 0) {
            if (column == size - 1 || array[row][column + 1] != 0) {
                direction = 1;
                row++;
            } else {
                column++;
            }
        } else if (direction == 1) {
            if (row == size - 1 || array[row + 1][column] != 0) {
                direction = 2;
                column--;
            } else {
                row++;
            }
        } else if (direction == 2) {
            if (column == 0 || array[row][column - 1] != 0) {
                direction = 3;
                row--;
            } else {
                column--;
            }
        } else if (direction == 3) {
            if (row == 0 || array[row - 1][column] != 0) {
                direction = 0;
                column++;
            } else {
                row--;
            }
        }
    }
    return array;
}


int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int **array = fillSpiral(size);
    if (array == NULL) {
        printf("Error");
        return 0;
    }
    // print the array with new line after each row
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", array[i][j]);
        }
          
    return 0;
    }
}

