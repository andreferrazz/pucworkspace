#include <stdio.h>

int main() {
    int r, x, y, z;
    x = 1;
    y = 12;
    z = 0;
    while (z < 5) {
        r = y % 3;
        if (r == 0) {
            x += 2;
        }
        y += 5;
        z += 1;
    }
    printf("x = %d\n", x);
}
