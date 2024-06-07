#include <stdio.h>
#include <string.h>

int main() {
    FILE *fptr = fopen("a1.txt", "r");
    char row[100];
    while (fgets(row, 100, fptr)) {
        char* token = strtok(row, ";");
        if (token != NULL) {
            token = strtok(NULL, ";");
            if (token != NULL) {
                printf("%s\n", token);
            }
        }
    }
}