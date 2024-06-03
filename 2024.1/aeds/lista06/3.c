#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **m, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] < 10)
                printf(" ");
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **create_matrix(int rows, int cols) {
    int n = 0;
    int **m = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m[i][j] = n++;
        }
    }
    return m;
}

int **add(int **a, int **b, int rows, int cols) {
    int **r = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        r[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
    return r;
}

int **sub(int **a, int **b, int rows, int cols) {
    int **r = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        r[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            r[i][j] = a[i][j] - b[i][j];
        }
    }
    return r;
}

int main() {
    const int rows = 4;
    const int cols = 6;
    int **a = create_matrix(rows, cols);
    int **b = create_matrix(rows, cols);
    print_matrix(a, rows, cols);
    print_matrix(b, rows, cols);
    int **s = add(a, b, rows, cols);
    int **d = sub(a, b, rows, cols);
    print_matrix(s, rows, cols);
    print_matrix(d, rows, cols);
}