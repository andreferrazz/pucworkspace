#include "student.c"

struct StudentList {
    struct Student *list;
    int size;
    int capacity;
} StudentList;

struct StudentList new_student_list(int capacity) {
    struct StudentList list;
    list.size = 0;
    list.capacity = capacity;
    list.list = (struct Student *)malloc(capacity * sizeof(Student));
    return list;
}

struct StudentList add_student(struct StudentList students, struct Student element) {
    if (students.size == students.capacity) {
        struct Student *list = students.list;
        students.capacity += students.capacity;
        students.list = (struct Student *)malloc(students.capacity * sizeof(Student));
        for (int i = 0; i < students.size; i++) {
            students.list[i] = list[i];
        }
        free(list);
    }
    students.list[students.size] = element;
    students.size++;
    return students;
}

void print_student_list(struct StudentList students) {
    printf("StudentList{");
    printf("\n\tcapacity: %d, ", students.capacity);
    printf("\n\tsize: %d, ", students.size);
    printf("\n\tlist: [\n");
    for (int i = 0; i < students.size; i++) {
        printf("\t\t");
        print_student(students.list[i]);
        if (i < students.size - 1) {
            printf(",\n");
        } else {
            printf("\n");
        }
    }
    printf("\t]");
    printf("\n}\n");
}