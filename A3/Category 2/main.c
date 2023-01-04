/*
    Scumpu Ioan Robert 916 (neon1024)
*/

// Category 2: Using dynamic memory allocation where is the case, solve one of the following: 1. Multiply 2 matrices of integers.

#include <stdio.h>
#include <stdlib.h>

int get_number_of_rows_from_console()
{
    int rows;

    printf("rows: ");
    scanf("%d", &rows);

    return rows;
}

int get_number_of_columns_from_console()
{
    int columns;

    printf("columns: ");
    scanf("%d", &columns);

    return columns;
}

void read_matrix(int **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
}

void multiply_matrices(int **result, int **matrix1, int rows1, int columns1, int **matrix2, int rows2, int columns2)
{
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void write_matrix(int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    printf("First matrix:\n");

    int rows1, columns1;

    rows1 = get_number_of_rows_from_console();
    columns1 = get_number_of_columns_from_console();

    int** matrix1 = (int**) malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*) malloc(columns1 * sizeof(int));
    }

    read_matrix(matrix1, rows1, columns1);

    printf("Second matrix:\n");

    int rows2, columns2;

    rows2 = get_number_of_rows_from_console();
    columns2 = get_number_of_columns_from_console();

    if (columns1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 0;
    }

    int** matrix2 = (int**) malloc(rows2 * sizeof(int*));

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*) malloc(columns2 * sizeof(int));
    }

    read_matrix(matrix2, rows2, columns2);

    int** result = (int**) malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        result[i] = (int*) malloc(columns2 * sizeof(int));
    }

    multiply_matrices(result, matrix1, rows1, columns1, matrix2, rows2, columns2);

    printf("Result:\n");

    write_matrix(result, rows1, columns2);

    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
