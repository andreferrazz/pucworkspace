#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int length) {
    printf("[");
    for (int i = 0; i < length; i++)
        printf(" %d ", a[i]);
    printf("] size = %d\n", length);
}

int exists(int *a, int length, int e) {
    for (int i = 0; i < length; i++)
        if (a[i] == e)
            return 1;
    return 0;
}

int *fun(int *v, int v_lenght, int *p_length) {
    int *p = malloc(v_lenght * sizeof(int));
    int count = 0;
    for (int i = 0; i < v_lenght; i++)
        if (exists(p, count, v[i]) == 0)
            p[count++] = v[i];
    (*p_length) = count;
    return p;
}

int main() {
    int p_length;
    int v[3] = {1, 3, 3};
    int *p = fun(v, 3, &p_length);
    printArray(p, p_length);
}