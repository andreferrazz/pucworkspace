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
    printf("    is_wild: %s\n", animal.is_domestic);
    printf("    max_weitgh: %d\n", animal.max_weight);
    printf("    max_age: %d\n", animal.max_age);
    printf("}\n");
}

void get_animals(struct Animal *animals, int *size) {
    FILE *input = fopen("arquivo-01.txt", "r");
    int idx = 0;
    char row[100];
    
    while (fgets(row, 100, input)) {
        if (strlen(row) == 0) {
            continue;
        }

        char *token = strtok(row, ";");
        if (token == NULL)
            continue;
        strcpy(animals[idx].name, token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        strcpy(animals[idx].scientific_name, token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        strcpy(animals[idx].is_domestic, token);

        token = strtok(NULL, ";");
        if (token == NULL)
            continue;
        animals[idx].max_weight = atoi(token);

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
    FILE *input = fopen("arquivo-02.txt", "r");
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
        for (int j = 0; j < animals_size; j++) {
            if (intervals[i][0] <= animals[j].max_weight && animals[j].max_weight <= intervals[i][1]) {
                printf("    %s\n", animals[j].name);
            }
        }
    }
}