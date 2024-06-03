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

int sum_below_main_diagonal(int **m, int length) {
    int r = 0;
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            r += m[i][j];
        }
    }
    return r;
}

void print_main_diagonal(int **m, int length) {
    printf("Diagonal principal: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", m[i][i]);
    }
    printf("\n");
}

int main() {
    const int n = 4;
    int **p = create_matrix(n);
    print_matrix(p, n, n);
    printf("Soma dos elementos abaixo da diagonal principal: %d\n", sum_below_main_diagonal(p, n));
    print_main_diagonal(p, n);
}