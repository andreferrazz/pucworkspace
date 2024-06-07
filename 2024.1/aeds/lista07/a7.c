#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("arquivo-01.txt", "r");
    FILE *out = fopen("arquivo-01_copia.txt", "w");
    char row[100];
    
    while (fgets(row, 100, input)) {
        fprintf(out, "%s", row);
    }

    fclose(input);
    fclose(out);
}