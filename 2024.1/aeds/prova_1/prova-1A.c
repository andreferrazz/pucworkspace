#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void questao_1() {
    puts("---------- QUESTÃO 1 ----------\n");
    int x, y;
    x = 0;
    y = 10;
    int i = 0;
    while (x < y) {
        x++;
        y--;
        i++;
    }
    printf("O loop foi executado %d vezes\n", i);
    printf("x = %d\n", x);
    printf("y = %d\n\n", y);
}

void questao_2() {
    puts("---------- QUESTÃO 2 ----------\n");
    float consumo;
    float preco;
    char eh_cadastrado_em_programas_sociais; // S/N
    
    puts("Entre com o consumo de energia do mes (kWh)");
    scanf("%f", &consumo);
    getchar();
    
    if (consumo < 0) {
        puts("Valor invalido! Encerrando programa...");
        return;
    }
    
    puts("Entre com o preco cobrado pela companhia de energia");
    scanf("%f", &preco);
    getchar();
    
    if (preco < 0) {
        puts("Valor invalido! Encerrando programa...");
        return;
    }
    
    puts("Possui cadastro em programs sociais (S/N)");
    scanf("%c", &eh_cadastrado_em_programas_sociais);
    getchar();
    
    eh_cadastrado_em_programas_sociais = toupper(eh_cadastrado_em_programas_sociais);
    
    if (eh_cadastrado_em_programas_sociais != 'S' && eh_cadastrado_em_programas_sociais != 'N') {
        puts("Valor invalido! Encerrando programa...");
        return;
    }
    
    float total_a_pagar = consumo * preco;
    
    if (eh_cadastrado_em_programas_sociais == 'S') {
        total_a_pagar *= 0.5;
    }
    
    printf("O valor da conta de luz é R$ %.2f\n\n", total_a_pagar);
}

void questao_3() {
    puts("---------- QUESTÃO 3 ----------\n");
    int n = 1;
    
    while(n % 3 != 2 || n % 5 != 3 || n % 7 != 4) {
        n++;
    }
    
    printf("N = %d\n\n", n);
}

void questao_4() {
    puts("---------- QUESTÃO 4 ----------\n");
    int n;
    
    puts("Entre com o valor de N");
    scanf("%d", &n);
    
    if (n <= 0) {
        puts("Valor invalido! Encerrando programa...");
        return;
    }
    
    printf("\n");
    
    int x = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", x);
            x++;
        }
        printf("\n");
    }
}

int main() {
    questao_1();
    questao_2();
    questao_3();
    questao_4();
}

