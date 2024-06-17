#include <assert.h>

int lucas(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return lucas(n - 1) + lucas(n - 2);
}

int main() {
    assert(0 == lucas(0));
    assert(1 == lucas(1));
    assert(1 == lucas(2));
    assert(2 == lucas(3));
    assert(3 == lucas(4));
    assert(5 == lucas(5));
}