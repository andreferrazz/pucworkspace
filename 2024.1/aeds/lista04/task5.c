#include <stdio.h>
#include <stdbool.h>

/*
 * Verifica se o numero eh primo
 *
 * Entrada:
 * 	n: numero a ser verificado
 *
 * Saida: true se n for primo ou false caso contrario
 */
bool ehPrimo(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

/*
 * Calcula os numeros primos mais proximos de m
 *
 * Entrada:
 * 	m: numero inteiro
 * 	p1: ponteiro para o primo menor que m
 * 	p2: ponteiro para o primo maior que m
 */
void primo(int m, int *p1, int *p2) {
	*p1 = m - 1;
	
	while (*p1 > 1 && !ehPrimo(*p1)) {
		(*p1)--;
	}

	if (*p1 <= 1) {
		*p1 = -1;
	}

	*p2 = m + 1;
	
	while (!ehPrimo(*p2)) {
		(*p2)++;
	}
}

int main() {
	int m, p1, p2;

	printf("Entre com um numero inteiro positivo: ");
	scanf("%d", &m);

	primo(m, &p1, &p2);

	printf("Maior número primo menor que %d é: %d\n", m, p1);
	printf("Menor número primo maior que %d é: %d\n", m, p2);
}
