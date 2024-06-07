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

void get_animals(struct Animal *animals, int *size) {
    FILE *input = fopen("a1.txt", "r");
    int idx = 0;
    char row[100];
    
    while (fgets(row, 100, input)) {
        if (strlen(row) == 0) {
            continue;
        }

        char *token = strtok(row, ";");
        if (token == NULL)
            continue;
        strcpy(animals[idx].nome, token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        strcpy(animals[idx].nome_cientifico, token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        strcpy(animals[idx].is_wild, token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        animals[idx].max_weitgh = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        animals[idx].max_age = atoi(token);

        idx++;
    }

    *size = idx;

    fclose(input);
}

void get_intervals(int intervals[20][2], int *size) {
    FILE *input = fopen("a2.txt", "r");
    int idx = 0;
    char row[100];
    
    while (fgets(row, 100, input)) {
        if (strlen(row) == 0) {
            continue;
        }

        char *token = strtok(row, ";");
        if (token == NULL)
            continue;
        intervals[idx][0] = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        intervals[idx][1] = atoi(token);

        idx++;
    }

    *size = idx;

    fclose(input);
}

int main() {
    struct Animal animals[20];
    int animals_size = 0;
    get_animals(animals, &animals_size);

    int intervals[20][2];
    int intervals_size = 0;
    get_intervals(intervals, &intervals_size);

    for (int i = 0; i < intervals_size; i++) {
        printf("[%d, %d]\n", intervals[i][0], intervals[i][1]);
    }
}