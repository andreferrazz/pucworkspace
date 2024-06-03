#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] < 10)
                printf(" ");
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int **create_matrix(int length) {
    int n = 0;
    int **m = malloc(4 * sizeof(int *));
    for (int i = 0; i < length; i++) {
        m[i] = malloc(length * sizeof(int));
        for (int j = 0; j < length; j++) {
            m[i][j] = n++;
        }
    }
    return m;
}

int sum_row(int **m, int length, int row) {
    int r = 0;
    for (int i = 0; i < length; i++) {
        r += m[row][i];
    }
    return r;
}

int sum_column(int **m, int length, int column) {
    int r = 0;
    for (int i = 0; i < length; i++) {
        r += m[i][column];
    }
    return r;
}

int sum_main_diagonal(int **m, int length) {
    int r = 0;
    for (int i = 0; i < length; i++) {
        r+= m[i][i];
    }
    return r;
}

int sum_secundary_diagonal(int **m, int length) {
    int r = 0;
    for (int i = 0, j = length - 1; i < length; i++, j--) {
        r+= m[i][j];
    }
    return r;
}

int sum_all(int **m, int length) {
    int r = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            r += m[i][j];
        }
    }
    return r;
}

int main() {
    const int n = 5;
    int **p = create_matrix(n);
    print_matrix(p, n, n);
    printf("Soma da linha 4: %d\n", sum_row(p, n, 4));
    printf("Soma da coluna 2: %d\n", sum_column(p, n, 2));
    printf("Soma da diagonal principal: %d\n", sum_main_diagonal(p, n));
    printf("Soma da diagonal secundaria: %d\n", sum_secundary_diagonal(p, n));
    printf("Soma dos elementos: %d\n", sum_all(p, n));
}
