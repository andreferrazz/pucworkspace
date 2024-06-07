#include <stdio.h>

struct Person {
    char name[100];
    int year;
    int month;
    int day;
} Person;

int compare(struct Person a, struct Person b) {
    if (a.year != b.year)
        return a.year - b.year;
    if (a.month != b.month)
        return a.month - b.month;
    return a.day - b.day;
}

int main() {
    struct Person people[6];
    struct Person youngest, oldest;

    for (int i = 0; i < 6; i++) {
        scanf("%[^,],%d,%d,%d\n", people[i].name, &people[i].year, &people[i].month, &people[i].day);
    }

    youngest = oldest = people[0];

    for (int i = 1; i < 6; i++) {
        if (compare(people[i], youngest) > 0) {
            youngest = people[i];
        }
        if (compare(people[i], oldest) < 0) {
            oldest = people[i];
        }
    }

    FILE *arquivo = fopen("out/b1.out", "w");
    fprintf(arquivo, "Youngest: %s\n", youngest.name);
    fprintf(arquivo, "Oldest: %s\n", oldest.name);
    fclose(arquivo);

    return 0;
}