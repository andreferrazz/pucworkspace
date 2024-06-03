#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define String char *

char *trim(char *str) {
    int idx = 0;
    int back_idx = strlen(str) - 1;

    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n') {
        idx++;
    }

    while (str[back_idx] == ' ' || str[back_idx] == '\t' || str[back_idx] == '\n') {
        back_idx--;
    }

    char *new_str = (char *)malloc((back_idx - idx + 2) * sizeof(char));

    for (int j = idx; j < back_idx + 1; j++) {
        new_str[j] = str[j];
    }

    new_str[back_idx + 1] = '\0';

    return new_str;
}

struct List {
    int capacity;
    int size;
    String *data;
} List;

struct List *init() {
    struct List *list = malloc(sizeof(List));

    if (list == NULL) {
        return NULL;
    }

    list->data = calloc(10, sizeof(String));

    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    list->capacity = 10;
    list->size = 0;
    return list;
}

void add(struct List *list, String str) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, sizeof(String) * list->capacity);
    }
    list->data[list->size] = malloc(sizeof(String));
    list->data[list->size++] = str;
}

void print_list(struct List *list) {
    printf("List{");
    printf("\n    capacity: %d, ", list->capacity);
    printf("\n    size: %d, ", list->size);
    printf("\n    list: [");
    for (int i = 0; i < list->size; i++) {
        printf(" %s ", list->data[i]);
    }
    printf("]");
    printf("\n}\n");
}

struct List *read_input() {
    struct List *values = init();
    size_t size = 100;
    char *buffer = (char *)malloc(size * sizeof(char));
    getline(&buffer, &size, stdin);
    int k = atoi(buffer);
    for (int i = 0; i < k; i++) {
        getline(&buffer, &size, stdin);
        add(values, trim(buffer));
    }
    free(buffer);
    return values;
}

bool _contains(char *a, char *b) {
    unsigned long a_length = strlen(a);
    unsigned long b_length = strlen(b);

    if (b_length > a_length) {
        return false;
    }

    char tmp[b_length + 1];

    for (int i = 0; i <= a_length - b_length; i++) {
        for (int j = 0; j < b_length; j++) {
            tmp[j] = a[i + j];
            if (j == b_length - 1)
                tmp[b_length] = '\0';
        }
        if (strcmp(b, tmp) == 0) {
            return true;
        }
    }
    return false;
}

int _count_potential_issues_for_one_password(struct List *passwords, int subject_idx,
                                             int current_idx, int acc) {
    if (current_idx >= passwords->size) {
        return acc - 1;
    }
    char *subject = passwords->data[subject_idx];
    char *current = passwords->data[current_idx];
    if (_contains(subject, current)) {
        acc++;
    }
    current_idx++;
    return _count_potential_issues_for_one_password(passwords, subject_idx, current_idx, acc);
}

int _count_potential_issues(struct List *passwords, int subject_idx, int acc) {
    if (subject_idx >= passwords->size) {
        return acc;
    }
    acc += _count_potential_issues_for_one_password(passwords, subject_idx, 0, 0);
    return _count_potential_issues(passwords, ++subject_idx, acc);
}

int count_potential_issues(struct List *passwords) {
    return _count_potential_issues(passwords, 0, 0);
}

int main(int argc, char **argv) {
    struct List *passwords = read_input();
    // print_list(passwords);
    printf("%d\n", count_potential_issues(passwords));
}
