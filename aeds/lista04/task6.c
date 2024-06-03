#inlude <stdio.h>
#include <math.h>

void teste(int n, int *b, int *k) {
    *b = 2;
    *k = 0;
    int temp;

    for (; *b < n; (*b)++) {
        *k = 0;
        temp = 1;
        
        while (temp < n) {
            temp *= *b;
            (*k)++;
        }
        
        if (temp == n) {
            return;
	}
    }

    *b = n;
    *k = 1;
}

int main() {
    int n, b, k;
    printf("Entre com um número n: ");
    scanf("%d", &n);
    teste(n, &b, &k);
    printf("O menor b tal que b^k = n é %d, e o respectivo k é %d.\n", b, k);
}

