#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal {
    char name[100];
    char scientific_name[100];
    bool is_domestic;
    int max_weight;
    int max_age;
} Animal;

void print(struct Animal animal) {
    printf("{ \n");
    printf("    name: %s,\n", animal.name);
    printf("    scientific_name: %s,\n", animal.scientific_name);
    printf("    is_domestic: %s,\n", animal.is_domestic ? "true" : "false");
    printf("    max_weitgh: %d,\n", animal.max_weight);
    printf("    max_age: %d\n", animal.max_age);
    printf("}\n");
}

int main() {
    int size = 0;
    int max_size = 20;
    struct Animal animals[max_size];
    FILE *input = fopen("in/arquivo-01.txt", "r");

    while (size < max_size) {
        char name[100];
        char scientific_name[100];
        char is_domestic[10];
        int max_weight;
        int max_age;
        char pattern[] = "%[^;];%[^;];%[^;];%d;%d;\n";
        int items_matched =
            fscanf(input, pattern, name, scientific_name, is_domestic, &max_weight, &max_age);

        if (items_matched != 5) {
            break;
        }

        strcpy(animals[size].name, name);
        strcpy(animals[size].scientific_name, scientific_name);
        animals[size].is_domestic = strcmp(is_domestic, "true") == 0;
        animals[size].max_weight = max_weight;
        animals[size].max_age = max_age;
        size++;
    }

    fclose(input);

    for (int i = 0; i < size; i++) {
        print(animals[i]);
    }
    printf("Size: %d\n", size);
}