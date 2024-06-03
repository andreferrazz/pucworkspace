#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f2(float vet[], int tam, float *y, float *z) {
    *z = 0;
    for (int i = 0; i < tam; i++) {
        *z = *z + pow((vet[i] - *y), 2);
    }
    *z = (float)*z / tam;
    *z = sqrt(*z);
}

void f1(float vet[], int tam, float *x, float *y, float *z) {
    *x = 0;
    for (int i = 0; i < tam; i++) {
        *x = *x + vet[i];
    }
    *y = *x / (float)tam;
    f2(vet, tam, y, z);
}

// Sera exibido "Baixo 2.0 10.0 50.0 5"
void task1() {
    int t = 5;
    float vet[5] = {10, 13, 11, 7, 9}, x, y, z;
    f1(vet, t, &x, &y, &z);

    if (z / y > 3.0) {
        printf("Alto %d %.1f %.1f %.1f", t, x, y, z);
    } else {
        printf("Baixo %.1f %.1f %.1f %d", z, y, x, t);
    }
}

int task2(char *str, int *b) {
    int a = 0;
    *b = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            a++;
        }
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            (*b)++;
        }
    }
    return a;
}

void task3() {
    int s;
    scanf("%d", &s);
    int **m = malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++) {
        m[i] = malloc(s * sizeof(int));
        for (int j = 0; j < s; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void f_task4(int **m, int s) {
    int v[s];
    for (int i = 0; i < s; i++) {
        v[i] = 0;
        for (int j = 0; j < s; j++) {
            v[i] += m[i][j];
        }
        v[i] /= s;
    }

    for (int i = 0; i < s; i++) {
        printf("%d ", v[i]);
    }
}

void task4() {
    int s;
    scanf("%d", &s);
    int **m = malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++) {
        m[i] = malloc(s * sizeof(int));
        for (int j = 0; j < s; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    f_task4(m, s);
}

struct Spot {
    int x;
    int y;
} Spot;

struct Person {
    struct Spot spot;
    int age;
} Person;

bool is_inside(struct Spot rect[4], struct Spot spot) {
    return spot.x > rect[0].x && spot.x < rect[1].x && spot.y > rect[2].y && spot.y < rect[0].y;
}

int count_children_inside(struct Person *people, int n, struct Spot rect[4]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (is_inside(rect, people[i].spot) && people[i].age < 18) {
            count++;
        }
    }
    return count;
}

void task5() {
    struct Person people[] = {
        {{0, 0}, 101}, {{1, 1}, 27}, {{2, 2}, 62}, {{3, 3}, 13}, {{4, 4}, 14}};
    struct Spot rect[] = {{0, 4}, {4, 4}, {0, 0}, {4, 0}};
    printf("%d\n", count_children_inside(people, 5, rect));
}

int main() {
    puts("Escolha uma das questoes abaixo.");
    puts("\t[1] Questao completamente sem sentido para se colocar numa prova");
    puts("\t[2] Questao mal elaborada");
    puts("\t[3] Ok, mas essa coisa de ficar lendo input do usuario já ta cansativo e nao agrega em nada");
    puts("\t[4] Ok");
    puts("\t[5] Novamente uma questao mal elaborada");
    int op;
    scanf("%d", &op);

    if (op < 1 || op > 5) {
        puts("Opcao invalida!");
        return 1;
    }

    int b;
    int a;

    switch (op) {
    case 1:
        task1();
        break;
    case 2:
        a = task2("AaBEC19D", &b);
        printf("a=%d b=%d\n", a, b);
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;
    }
}