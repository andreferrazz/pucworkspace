#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_float(float min, float max) { return min + ((float)rand() / RAND_MAX) * (max - min); }

float **create_matrix(int rows, int cols) {
    srand(time(NULL));
    float **m = malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++) {
            m[i][j] = random_float(0, 10.0);
        }
    }
    return m;
}

void print_matrix(float **m, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Entre com numero: ");
    scanf("%d", &n);
    float **a = create_matrix(n, n);
    print_matrix(a, n, n);
}