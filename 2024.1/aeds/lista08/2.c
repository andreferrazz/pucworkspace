#include <stdio.h>
#include <stdbool.h>

void fun(int e, bool increment, int min, int max) {
    if (e < min) {
        return;
    }
    
    printf("%d ", e);

    if (e == max) {
        increment = false;
        printf("%d ", e);
    }

    fun(increment ? ++e : --e, increment, min, max);
}

int main() {
    fun(1, true, 1, 5);
}