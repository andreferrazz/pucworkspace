#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("arquivo-02.txt", "r");
    FILE *out = fopen("arquivo-02.bin", "w");
    char row[100];
    
    while (fgets(row, 100, input)) {
        fprintf(out, "%s", row);
    }

    fclose(input);
    fclose(out);
}