#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_uppercase(char *str, int size, int i, int acc) {
    if (i >= size) {
        return acc;
    }

    if (str[i] >= 'A' && str[i] <= 'Z') {
        acc++;
    }

    return count_uppercase(str, size, ++i, acc);
}

int main() {
    size_t size = 100;
    char *buffer = (char *)malloc(size * sizeof(char));
    getline(&buffer, &size, stdin);
    while (strcmp(buffer, "FIM\n") != 0) {
        int count = count_uppercase(buffer, strlen(buffer), 0, 0);
        printf("%d\n", count);
        getline(&buffer, &size, stdin);
    }
    free(buffer);
}