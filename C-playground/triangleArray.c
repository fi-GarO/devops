#include <stdio.h>
#include <stdlib.h>

// alocate array in a shape of a triangle
int **allocateTriangleArray(int size) {
    int **array = (int **)malloc(size * sizeof(int *));
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        array[i] = (int *)malloc((i + 1) * sizeof(int));
        if (array[i] == NULL) {
            return NULL;
        }
    }
    return array;
}


// allocate array in a shape of a triangle and fill it with number from 1 to size
int **fillTriangleArray(int size) {
    int **array = allocateTriangleArray(size);
    if (array == NULL) {
        return NULL;
    }
    int index = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            array[i][j] = index;
            index++;
        }
    }
    return array;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 10;   
    int **triangle = allocateTriangleArray(size);
    if (triangle == NULL) {
        printf("Error");
        return 0;
    }
    triangle = fillTriangleArray(size);
    if (triangle == NULL) {
        printf("Error");
        return 0;
    }


    // Print the triangle
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i < size; i++){
        free(triangle[i]);
    }
    free(triangle);
    return 0;
}
