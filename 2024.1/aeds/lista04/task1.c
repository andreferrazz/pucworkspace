#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* askForDate() {
	char* date = NULL;
	size_t len = 0;
	puts("Entre com uma data no formato d/m/y ");
	getline(&date, &len, stdin);
	return date;
}

int countDaysSinceJesusChrist(char* date) {
	int day = atoi(strtok(date, "/"));
	int month = atoi(strtok(NULL, "/"));
	int year = atoi(strtok(NULL, "/"));
	return year * 365 + month * 30 + day;
}

int dateDiff(char* a, char* b) {
	int x = countDaysSinceJesusChrist(a);
	int y = countDaysSinceJesusChrist(b);
	if (x > y) return x - y;
	return y - x;
}

int main() {
	char* a = askForDate();
	char* b = askForDate();
	printf("%d\n", dateDiff(a, b));
}
