#include <stdio.h>
#include <stdlib.h>

int main() {
    int s;
    scanf("%d\n", &s);
    int **m = malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++) {
        m[i] = malloc(s * sizeof(int));
        for (int j = 0; j < s; j++) {
            scanf("%d\n", &m[i][j]);
        }
    }
}