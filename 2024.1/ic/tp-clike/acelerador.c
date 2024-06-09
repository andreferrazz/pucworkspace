#include <assert.h>

int sensor(int d) {
    int res = (d % 8) - 5;
    return (res == -5) ? 3 : res;
}

int main() {
    assert(1 == sensor(6));
    assert(2 == sensor(23));
    assert(3 == sensor(9192));
}