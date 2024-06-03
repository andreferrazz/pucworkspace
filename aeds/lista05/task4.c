#include <stdio.h>
#include <string.h>

char* readLine() {
	char* str = NULL;
	size_t len = 0;
    printf("Escreva a senha: ");
	getline(&str, &len, stdin);
    str[strcspn(str, "\n")] = 0;
	return str;
}

int main() {
    char* password = readLine();
    int size = strlen(password);

    if (size < 8) {
        puts("Invalid password. Min size is 8.");
        return 1;
    }

    int qtd_uppercase = 0;
    int qtd_lowercase = 0;
    int qtd_digits = 0;
    int qtd_special = 0;

    for (int i = 0; i < size; i++) {
        if (password[i] >= 65 && password[i] <= 90) qtd_uppercase++;
        else if (password[i] >= 97 && password[i] <= 122) qtd_lowercase++;
        else if (password[i] >= 48 && password[i] <= 57) qtd_digits++;
        else qtd_special++;
    }

    if (qtd_uppercase == 0) {
        puts("Invalid password. At least one capital letter is required.");
        return 1;
    }

    if (qtd_lowercase == 0) {
        puts("Invalid password. At least one lowercase letter is required.");
        return 1;
    }

    if (qtd_digits == 0) {
        puts("Invalid password. At least one digit is required.");
        return 1;
    }

    if (qtd_special == 0) {
        puts("Invalid password. At least one special character is required.");
        return 1;
    }

    puts("Password is valid");
}
    
