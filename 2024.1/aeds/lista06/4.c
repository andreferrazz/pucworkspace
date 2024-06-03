#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **m, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int create_element(int i, int j) {
    if (i == j)
        return (i * i * 3) - 1;
    else if (i < j)
        return (2 * i) + (7 * j) - 2;
    else
        return (4 * i * i * i) - (5 * j * j) + 1;
}

int **create_matrix(int rows, int cols) {
    int **m = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m[i][j] = create_element(i, j);
        }
    }
    return m;
}

int main() {
    const int rows = 10;
    const int cols = 10;
    int **a = create_matrix(rows, cols);
    print_matrix(a, rows, cols);
}