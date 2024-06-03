#include <stdio.h>

int main() {
	int count = 0;
	int candidate;
	do {
		puts("Entre com um valor inteiro");
		scanf("%d", &candidate);
		if (candidate % 3 == 0 && candidate != 0) {
			count++;
		}
	} while (candidate != 0);
	printf("Result: %d\n", count);
}
