#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Requisita uma data via stdin
 *
 * Entrada:
 *	date: onde sera armazenado
 */
void askForDate(char* date, size_t len) {
	puts("Entre com uma data no formato d/m/y ");
	getline(&date, &len, stdin);
}

/*
 * Conta a quantidade de dias ocorridos desde de Jesus Cristo
 *
 * Entrada:
 *	date: string no formato d/m/y
 *
 * Saida: quantidade de dias ocorridos
 */
int countDaysSinceJesusChrist(char date[]) {
	char* part = strtok(date, "/");
	int day = atoi(part);
	int month = atoi(strtok(NULL, "/"));
	int year = atoi(strtok(NULL, "/"));
	return year * 365 + month * 30 + day;
}

/*
 * Calcula a diferenca de dias entre duas datas
 *
 * Entrada:
 *	a: string no formato d/m/y
 *	b: string no formato d/m/y
 *
 * Saida: dias de diferenca
 */
int dateDiff(char* a, char* b) {
	int x = countDaysSinceJesusChrist(a);
	int y = countDaysSinceJesusChrist(b);
	if (x > y) return x - y;
	return y - x;
}

int main() {
	char* a = malloc(11 * sizeof(char));
	askForDate(a, 11);
	char* b = malloc(11 * sizeof(char));
	askForDate(b, 11);
	printf("%d\n", dateDiff(a, b));
	free(a);
	free(b);
}
