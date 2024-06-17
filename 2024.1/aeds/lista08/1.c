#include <stdio.h>
#include <stdbool.h>

void fun(int e, bool increment) {
    if (e == 0) {
        return;
    }
    
    printf("%d ", e);

    if (e == 5) {
        increment = false;
        printf("%d ", e);
    }

    fun(increment ? ++e : --e, increment);
}

int main() {
    fun(1, true);
}