#include <stdio.h>

void fun(int *v, int size, FILE *file) {
    if (size == 0) {
        return;
    }
    fprintf(file, "%d ", v[--size]);
    fun(v, size, file);
}

int main() {
    FILE *file = fopen("saida.txt", "w");
    int v[3] = { 1, 2, 3 };
    fun(v, 3, file);
    fclose(file);
}