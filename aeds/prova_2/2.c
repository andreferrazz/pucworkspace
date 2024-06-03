#include <stdio.h>
#include <string.h>

int f(char *str, int *b) {
    int a = 0;
    *b = 0;
    for (int i =0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            a++;
        }
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            (*b)++;
        }
    }
    return a;
}

int main() {
    int b;
    int a = f("AaBEC19D", &b);
    printf("a=%d b=%d\n", a, b);
}