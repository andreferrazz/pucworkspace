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

    FILE *out = fopen("saida.txt", "w");

    int min = animals[0].max_weitgh;
    int max = animals[0].max_weitgh;
    int avg = 0;
    for (int i = 0; i < size; i++) {
        if (animals[i].max_weitgh < min) {
            min = animals[i].max_weitgh;
        } 
        
        if (animals[i].max_weitgh > max) {
            max = animals[i].max_weitgh;
        } 

        avg += animals[i].max_weitgh;
        print(animals[i]);
    }

    avg /= size;

    fprintf(out, "Min: %d\n", min);
    fprintf(out, "Max: %d\n", max);
    fprintf(out, "Avg: %d\n", avg);
    fclose(out); 
}