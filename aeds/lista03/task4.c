#include <stdio.h>

int main() {
	int n;
	puts("Entre com um numero inteiro positivo");
	scanf("%d", &n);
	float sum = 0;
	for(int i = n; i > 0; i--) {
		sum += 1.0 / i;
	}
	printf("S = %f\n", sum);
}
