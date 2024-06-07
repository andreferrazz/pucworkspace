#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal {
    char nome[100];
    char nome_cientifico[100];
    char is_wild[10];
    int max_weitgh;
    int max_age;
} Animal;

void print(struct Animal animal) {
    printf("Animal{ \n");
    printf("    nome: %s\n", animal.nome);
    printf("    nome_cientifico: %s\n", animal.nome_cientifico);
    printf("    is_wild: %s\n", animal.is_wild);
    printf("    max_weitgh: %d\n", animal.max_weitgh);
    printf("    max_age: %d\n", animal.max_age);
    printf("}\n");
}

int main() {
    FILE *input = fopen("a1.txt", "r");
    struct Animal animals[20];
    int size = 0;
    char row[100];
    while (fgets(row, 100, input)) {
        if (strlen(row) == 0) {
            continue;
        }

        char *token = strtok(row, ";");
        if (token == NULL) continue;
        strcpy(animals[size].nome, token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(animals[size].nome_cientifico, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(animals[size].is_wild, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        animals[size].max_weitgh = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        animals[size].max_age = atoi(token);

        size++;
    }

    fclose(input);

    for (int i = 0; i < size; i++) {
        if (animals[i].max_age > 10 && animals[i].max_age < 16) {
            puts(animals[i].nome);
        }
    }
}