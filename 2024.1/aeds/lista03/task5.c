#include <stdio.h>

int main() {
	float valor;
	float total = 0;
	float max = 0;
	int dia = 1;
	for(int i = 0; i < 31; i++) {
		printf("Entre com o indice pluviometrico do dia %d\n", i + 1);
		scanf("%f", &valor);
		if (valor > max) {
			max = valor;
			dia = i + 1;
		}
		total += valor;
	}
	printf("Indice pluviometrico medio: %.1f\n", total / 31);
	printf("Indice pluviometrico maximo: %.1f\n", max);
	printf("Dia do indice maximo: %d\n", dia);
}
