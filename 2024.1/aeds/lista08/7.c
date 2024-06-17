#include <stdio.h>

float fun(int n, float acc) {
    if (n == 0) {
        return acc;
    }
    return fun(--n, acc + (1.0 / n));
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%f\n", fun(n, 0));
}