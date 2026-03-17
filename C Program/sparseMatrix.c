#include <stdio.h>

int main() {
    int matrix[10][10], rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nNon-zero elements in sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("%d\t%d\t%d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}
