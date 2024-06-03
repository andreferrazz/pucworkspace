#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Descricao: 
 *     Transforma cada caractere da string em maiuscula
 * Input:
 *     char* vetor
 * Outout:
 *     a string uppercase
 */
char* capitalizeString(char *vetor, int tamanho) {
    char* str = malloc((tamanho + 1) * sizeof(char));
    for (int i = 0; i < tamanho; i++) {
        str[i] = vetor[i] - 32;
    }
    return str;
}

char* read_line() {
    char* str = NULL;
    size_t len = 0;
    printf("Entre com um texto em letras minusculas: ");
    getline(&str, &len, stdin);
    str[strcspn(str, "\n")] = 0;
    return str;
}

int main() {
    char* text = read_line();
    char* result = capitalizeString(text, strlen(text));
    puts(result);
    free(result);
}
