#include <assert.h>

int divisao(int numerador, int denominador) {
    if (numerador - denominador < 0) {
        return 0;
    }
    return 1 + divisao(numerador - denominador, denominador);
}

int main() {
    assert(4 == divisao(20, 5));
    assert(5 == divisao(20, 4));
    assert(5 == divisao(10, 2));
    assert(10 == divisao(100, 10));
}