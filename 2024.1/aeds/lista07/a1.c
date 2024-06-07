#include <stdio.h>

int main() {
    FILE *fptr = fopen("arquivo-01.txt", "r");
    int i = 0;
    char str[100];
    while (fgets(str, 100, fptr)) {
        i++;
    }
    printf("%d", i);
}