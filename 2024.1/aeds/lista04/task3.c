#include <stdio.h>

/*
 * Inverte dois valores inteiro
 *
 * Entrada:
 * 	x: ponteiro de um valor inteiro
 * 	y: ponteiro de um valor inteiro
 */
void troca(int* x, int* y){
	int aux; // Declara uma variavel do tipo inteiro
	aux = *x; // Atribui a `aux` o valor apontado por x
	*x  = *y; // Cria uma copia do valor apontado por y em x
	*y  = aux; // Cria uma copia de aux em y
}

int main() {
	int a = 5, b = 2; // Declara e inicializa duas variaveis do tipo inteiro
	troca(&a, &b); // Chama a funcao passando os ponteiros de a e b
	printf("\n%i, %i", a, b); // Mostra na tela os valores de a e b, "2, 5"
}

