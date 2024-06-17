#include <assert.h>
#include <stdbool.h>

int a(char *s, int acc) {
    if (s[acc] == '\0') {
        return acc;
    }
    return a(s, ++acc);
}

int b(char *s) {
    int acc = 0;
    while (s[acc] != '\0') {
        acc++;
    }
    return acc;
}

int main() {
    assert(3 == a("abc", 0));
    assert(3 == b("abc"));
}