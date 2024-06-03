#include <stdio.h>
#include <stdlib.h>

char* capitalizeString(char *vetor, int tamanho) {
    char* result = malloc(tamanho * sizeof(char));
    for (int i = 0; i < tamanho; i++) {
        result[i] = vetor[i] - 32;
    }
    return result;
}

int main() {
    char* str = "abc";
    char* result = capitalizeString(str, 3);
    puts(result);
}
