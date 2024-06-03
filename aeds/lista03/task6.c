#include <stdio.h>

int main() {
	int n;
	puts("Entre com um valor inteiro positivo");
	scanf("%d", &n);

	if (n < 1) {
		puts("Valor invalido");
		return 1;
	}

	printf("1 ");

	int current = 1;
	int previous = 1;
	int aux;
	for(int i = 1; i < n; i++) {
		if (i == 1) {
			printf("1 ");
		} else {
			printf("%d ", current + previous);
			aux = previous;
			previous = current;
			current = current + aux;
		}
	}
}
