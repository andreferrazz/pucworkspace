#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrayList {
    int *list;
    int size;
    int capacity;
} ArrayList;

struct ArrayList *new_array_list(int capacity) {
    struct ArrayList *array_list = malloc(sizeof(ArrayList));
    array_list->size = 10;
    array_list->capacity = capacity;
    array_list->list = malloc(capacity * sizeof(int));
    for (int i = 0; i< capacity; i++) {
        array_list->list[i] = i;
    }
    return array_list;
}

void add(struct ArrayList *list, int element) {
    // if (list.size == list.capacity) {
    //     int *arr = list.list;
    //     list.capacity += list.capacity;
    //     list.list = (struct Student *)malloc(list.capacity * sizeof(int));
    //     for (int i = 0; i < list.size; i++) {
    //         memcpy((list.list + (i * sizeof(int))), (arr + (i * sizeof(int))), sizeof(int));
    //     }
    //     free(arr);
    // }
    list->list[list->size] = element;
    list->size++;
}

void print_student_list(struct ArrayList *list) {
    printf("ArrayList{");
    printf("\n\tcapacity: %d, ", list->capacity);
    printf("\n\tsize: %d, ", list->size);
    printf("\n\tlist: [");
    for (int i = 0; i < list->size; i++) {
        // printf("\n\t\t");
        printf(" %d ", *((int *)list->list + (i * sizeof(int))));
        // if (i < list->size - 1) {
        //     printf(",");
        // } else {
        //     printf("\n\t");
        // }
    }
    printf("]");
    printf("\n}\n");
}

int main() {
    struct ArrayList *array_list = new_array_list(10);
    // int a = 8;
    // int b = 3;
    // add(array_list, a);
    // add(array_list, b);
    // array_list = add(array_list, 4);
    // array_list = add(array_list, 7);
    print_student_list(array_list);
}