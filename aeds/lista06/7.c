#include <stdio.h>
#include "7/studentlist.c"

struct StudentList read_file(char *filename, int limit) {
    FILE *file = fopen(filename, "r");

    struct StudentList students = new_student_list(10);

    int idx = 0;
    char rows[limit][100];
    char row[100];
    while (fgets(row, 100, file) && idx < limit) {
        strcpy(rows[idx++], row);
    }

    fclose(file);

    for (int i = 0; i < idx; i++) {
        struct Student student = create_student(rows[i]);
        students = add_student(students, student);
    }

    return students;
}

struct Student get_student_with_best_final_grade(struct StudentList students) {
    struct Student student = students.list[0];

    for (int i = 1; i < students.size; i++) {
        if (students.list[i].final_grade > student.final_grade) {
            student = students.list[i];
        }
    }

    return student;
}

int main() {
    struct StudentList students = read_file("alunos.csv", 100);
    // print_student_list(students);
    struct Student best_student = get_student_with_best_final_grade(students);
    printf("The best student is %s\n", best_student.name);
}