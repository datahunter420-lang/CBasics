#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows_size, cols_size;

    printf("Enter the size of rows: ");
    scanf("%d", &rows_size);
    printf("Enter the size of cols: ");
    scanf("%d", &cols_size);

    // Step 1: allocate array of row pointers
    int **arrarr = calloc(rows_size, sizeof(int *));

    // Step 2: allocate each row
    for (int i = 0; i < rows_size; i++) {
        arrarr[i] = calloc(cols_size, sizeof(int));
    }

    // Fill with row*col values
    printf("Filling matrix with row x col values...\n");
    for (int i = 0; i < rows_size; i++) {
        for (int j = 0; j < cols_size; j++) {
            arrarr[i][j] = (i + 1) * (j + 1);  // row×col formula
        }
    }

    // Print as matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < rows_size; i++) {
        for (int j = 0; j < cols_size; j++) {
            printf("%4d", arrarr[i][j]);
        }
        printf("\n");
    }

    // Free all memory properly
    for (int i = 0; i < rows_size; i++) {
        free(arrarr[i]);    // free each row first
    }
    free(arrarr);           // then free the pointer array

    return 0;
}