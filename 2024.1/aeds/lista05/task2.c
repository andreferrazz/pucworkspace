#include <stdio.h>

/*
    Descrição: Recebe do stdin 10 notas e armazena no array
    Entrada: tam (inteiro), vetor (int array), 
    Saída: void
*/
void preencheNotas(int tam, int vetor[]) {
    for (int i = 0; i < 10; i++) {
        printf("Entre com a nota: ");
        scanf("%d", &vetor[i]);
    }
}

/*
    Descrição: calcula a media de 10 notas e imprime na tela
    Entrada: tam (inteiro), vetor (int array), 
    Saída: void
*/
void calculaMedia(int tam, int vetor[]) {
    float media = 0;

    for (int i = 0; i < 10; i++) {
        media += vetor[i];
    }

    media /= 10;

    int qtd = 0;

    for (int i = 0; i < 10; i++) {
        if (vetor[i] > media) qtd++;
    }

    printf("Media das notas: %.2f\n", media);
    printf("Notas acima da media: %d\n", qtd);
}

int main() {
    int arr[10];
    preencheNotas(10, arr); 
    calculaMedia(10, arr); 
}
