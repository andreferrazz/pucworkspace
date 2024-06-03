#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * Descricao: 
 *     verifica se o email contem o caractere @
 * Input:
 *     char email
 * Output:
 *     Index do carcatere @ ou -1 se ausente
 */
int isEmailValid(char* email) {
    for (int i = 0; i < strlen(email); i++)
        if (email[i] == '@')
            return i;
    return -1;
}

char* readLine() {
	char* str = NULL;
	size_t len = 0;
    printf("Escreva o email: ");
	getline(&str, &len, stdin);
    str[strcspn(str, "\n")] = 0;
	return str;
}

int main() {
    char* email = readLine();
    bool isValid = isEmailValid(email) != -1;
    printf("The email is %s\n", isValid ? "valid" : "invalid");
}
