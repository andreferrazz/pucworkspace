#include <stdio.h>

void imprimir_reversa(char *str, int tamanho) {
    if (tamanho == 0) {
        printf("\n");
        return;
    }
    printf("%c", str[--tamanho]);
    imprimir_reversa(str, tamanho);
}

int main() {
    imprimir_reversa("abcde", 5);
    imprimir_reversa("abcd", 4);
}