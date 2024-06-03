#include <math.h>
#include <stdio.h>

void f2(float vet[], int tam, float *y, float *z) {
    *z = 0;
    for (int i = 0; i < tam; i++) {
        *z = *z + pow((vet[i] - *y), 2);
    }
    *z = (float)*z / tam;
    *z = sqrt(*z);
}

void f1(float vet[], int tam, float *x, float *y, float *z) {
    *x = 0;
    for (int i = 0; i < tam; i++) {
        *x = *x + vet[i];
    }
    *y = *x / (float)tam;
    f2(vet, tam, y, z);
}

// Sera exibido "Baixo 2.0 10.0 50.0 5"
int main() {
    int t = 5;
    float vet[5] = {10, 13, 11, 7, 9}, x, y, z;
    f1(vet, t, &x, &y, &z);

    if (z / y > 3.0) {
        printf("Alto %d %.1f %.1f %.1f", t, x, y, z);
    } else {
        printf("Baixo %.1f %.1f %.1f %d", z, y, x, t);
    }
}