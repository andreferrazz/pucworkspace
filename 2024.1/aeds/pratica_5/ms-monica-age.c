#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 100;
    char *buffer = (char *)malloc(size * sizeof(char));
    getline(&buffer, &size, stdin);
    int m = atoi(buffer);
    getline(&buffer, &size, stdin);
    int a = atoi(buffer);
    getline(&buffer, &size, stdin);
    int b = atoi(buffer);
    int c = m - a - b;
    int maior = a > b ? a : b;
    maior = c > maior ? c : maior;
    printf("%d\n", maior);
    free(buffer);
}