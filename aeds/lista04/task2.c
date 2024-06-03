#include <stdio.h>

void show() { puts("Exercicio 2"); }

float sum(float a, float b) { return a + b; }

void printResult(float n) { printf("%f\n", n); }

int main() {
	show();
	float result = sum(4.3, 5.1);
	printResult(result);
}
