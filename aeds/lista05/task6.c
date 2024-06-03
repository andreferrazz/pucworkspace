#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct WordCount {
    char word[50];
    int count;
} WordCount;

/*
 * Descricao: 
 *     Conta a quantidade de cada palavra e imprimi no stdout
 * Input:
 *     char* texto
 */
void count_words(char* text) {
    struct WordCount* words = malloc(50 * sizeof(WordCount));
    int j = 0;

    char word[100];
    int word_index = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != ' ' && i != strlen(text) - 1) {
            word[word_index++] = text[i];
        } else {
            if (i == strlen(text) - 1) {
                word[word_index++] = text[i];
            }
            word[word_index] = '\0';
            
            int existing = -1;
            if (j > 0) {
                for (int g = 0; words[g].count > 0; g++) {
                    if (strcmp(word, words[g].word) == 0) {
                        existing = g;
                    }
                }
            }

            if (existing == -1) {
                strcpy(words[j].word, word);
                words[j].count = 1;
                words[++j].count = 0;
                word_index = 0;
            } else {
                words[existing].count++;
                word_index = 0;
            }

        }
    }

    for (int i = 0; words[i].count > 0; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);
}

char* read_line() {
    char* str = NULL;
    size_t len = 0;
    printf("Entre com uma frase: ");
    getline(&str, &len, stdin);
    str[strcspn(str, "\n")] = 0;
    return str;
}

int main() {
    char* text = read_line();
    count_words(text);
}
