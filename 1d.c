#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the order of the matrix (rows and columns): ");
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    int transpose[cols][rows];
    printf("Enter the coefficients of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the original matrix
    printf("The given matrix is:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the transpose of the matrix
    printf("Transpose of the matrix is:\n");
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
