#include <stdio.h>

/*
    Descrição: imprime um array no stdout.
    Entrada: arr (array inteiro), size (int), 
    Saída: void
*/
void printArray(float* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%f", arr[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    float arr[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter an integer value: ");
        scanf("%f", &arr[i]);
    }

    float doubled[5] = {0,0,0,0,0};

    for (int i = 0; i < 5; i++) {
        doubled[i] = arr[i] * 2;
    }

    printArray(doubled, 5); 
}
