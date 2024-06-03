#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Descrição: imprime um array no stdout.
 * Entrada: arr (array inteiro), size (int), 
 * Saída: void
 */
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

/*
 * Descrição: Preenche dois vetores com valores aleatorios
 * Entrada: x (array inteiro), y (array inteiro), length (int)
 * Saída: void
 */
void preencheValores(int x[], int y[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        x[i] = 10 + rand() % (20 - 10 + 1);
        y[i] = 10 + rand() % (20 - 10 + 1);
    }
}

/*
 * Descrição: Preenche um vetor com os valores de dois outros vetores de forma intercalada
 * Entrada: x (array inteiro), y (array inteiro), length (int), z (array inteiro)  
 * Saída: void
 */
void intercala(int x[], int y[], int length, int z[]) {
    for(int i = 0, z_index = 0; i < length; i++, z_index += 2) {
        z[z_index] = y[i];
        z[z_index + 1] = x[i];
    }
}

int main() {
    int x[10];
    int y[10];
    int z[20];
    preencheValores(x, y, 10);
    intercala(x, y, 10, z);
    printArray(x, 10);
    printArray(y, 10);
    printArray(z, 20);
}
