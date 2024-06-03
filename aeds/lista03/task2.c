#include <stdio.h>

int main() {
	int n;
	puts("Entre com com um numero inteiro");
	scanf("%d", &n);
	while(n > 1) {
		printf("%d ", --n);
	}
}
