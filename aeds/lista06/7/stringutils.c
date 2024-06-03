#include <string.h>
#include <stdlib.h>

char *trim(char *str) {
    int idx = 0;
    int back_idx = strlen(str) - 1;

    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n') {
        idx++;
    }

    while (str[back_idx] == ' ' || str[back_idx] == '\t' || str[back_idx] == '\n') {
        back_idx--;
    }

    char *new_str = (char *)malloc((back_idx - idx + 2) * sizeof(char));

    for (int j = idx; j < back_idx; j++) {
        new_str[j] = str[j];
    }

    new_str[back_idx] = '\0';

    return new_str;
}