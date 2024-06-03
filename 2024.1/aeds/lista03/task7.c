#include <stdio.h>

int main() {
	int n;
	puts("Entre com um numero inteiro");
	scanf("%d", &n);

	int count = 0;

	while(n != 0) {
		n = n / 10;
		count++;
	}

	printf("%d digitos\n", count);
}
