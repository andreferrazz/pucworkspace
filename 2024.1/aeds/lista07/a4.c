#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal {
    char name[100];
    char scientific_name[100];
    char is_domestic[10];
    int max_weight;
    int max_age;
} Animal;

void print(struct Animal animal) {
    printf("Animal{ \n");
    printf("    name: %s\n", animal.name);
    printf("    scientific_name: %s\n", animal.scientific_name);
    printf("    is_domestic: %s\n", animal.is_domestic);
    printf("    max_weitgh: %d\n", animal.max_weight);
    printf("    max_age: %d\n", animal.max_age);
    printf("}\n");
}

int main() {
    FILE *input = fopen("arquivo-01.txt", "r");
    struct Animal animals[20];
    int size = 0;
    char row[100];
    while (fgets(row, 100, input)) {
        if (strlen(row) == 0) {
            continue;
        }

        char *token = strtok(row, ";");
        if (token == NULL) continue;
        strcpy(animals[size].name, token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(animals[size].scientific_name, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(animals[size].is_domestic, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        animals[size].max_weight = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        animals[size].max_age = atoi(token);

        size++;
    }

    fclose(input);

    for (int i = 0; i < size; i++) {
        if (animals[i].max_age > 10 && animals[i].max_age < 16) {
            puts(animals[i].name);
        }
    }
}