#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void questao_1() {
    puts("---------- QUESTÃO 1 ----------\n");
    int x, y;
    x = 2;
    y = 13;
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
    
    while(n % 3 != 1 || n % 5 != 2 || n % 7 != 5) {
        n++;
    }
    
    printf("N = %d\n\n", n);
}

void questao_4() {
    puts("---------- QUESTÃO 4 ----------\n");
    int a; 
    int b;
    
    puts("Entre com dois valores inteiros positivos");
    scanf("%d %d", &a, &b);
    
    if (a <= 0 || b <= 0) {
        puts("Um ou mais valores invalidos! Encerrando programa...");
        return;
    }    
    
    bool ehPrimo = true;
    int menor = a < b ? a : b;
    
    for (int i = 2; i <= menor; i++) {
        if (a % i == 0 && b % i == 0) {
            ehPrimo = false;
            break;
        }
    }
    
    if (ehPrimo) {
        puts("Os numeros sao primos\n\n");
    } else {
        puts("Os numeros nao sao primos\n\n");
    }
}

int main() {
    questao_1();
    questao_2();
    questao_3();
    questao_4();
}

