#include <stdio.h>

int main() {
    int d;
    scanf("%d", &d);
    int res = (d % 8) == 0 ? 3 : (d % 8) - 5;
    printf("%d", res);
}