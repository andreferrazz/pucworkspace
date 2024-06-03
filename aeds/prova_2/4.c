#include <stdio.h>
#include <stdlib.h>

void f(int **m, int s) {
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

    f(m, s);
}