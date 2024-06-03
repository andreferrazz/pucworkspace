#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringutils.c"

struct Student {
    char id[10];
    char name[50];
    float n1;
    float n2;
    float n3;
    float final_grade;
} Student;

struct Student create_student(char *row) {
    char **tokens = (char **)malloc(6 * sizeof(char *));
    char *token = strtok(trim(row), " ");

    for (int j = 0; j < 6 && token != NULL; j++) {
        tokens[j] = token;
        token = strtok(NULL, " ");
    }

    struct Student student;
    strcpy(student.name, tokens[0]);
    strcpy(student.id, tokens[1]);
    student.n1 = atof(tokens[2]);
    student.n2 = atof(tokens[3]);
    student.n3 = atof(tokens[4]);
    student.final_grade = (student.n1 + student.n2 + student.n3) / 3.0;
    return student;
}

void print_student(struct Student student) {
    printf("Student{ ");
    printf("id: \"%s\", ", student.id);
    printf("name: \"%s\", ", student.name);
    printf("n1: %.2f, ", student.n1);
    printf("n2: %.2f, ", student.n2);
    printf("n3: %.2f, ", student.n3);
    printf("final_grade: %.2f", student.final_grade);
    printf(" }");
}
