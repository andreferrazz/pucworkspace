#include <stdio.h>

int exercicio_1(float a, float b, float c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return 0;
    }
    
    if (a == b && a == c) {
        return 1;
    }
    
    if (a != b && a != c && b != c) {
        return 3;
    }
    
    return 2;
}

int exercicio_2(int a, int b) {

}


int exercicio_3(int data) {

}


void exercicio_4() {
    int op = -1;
    puts("-------------------- MENU --------------------");
    puts("Ola! Qual algoritmo voce gostaria de testar?");
    puts("(1) Tipo do triangulo");
    puts("(2) Calculo de MDC");
    puts("(3) Validador de data");
    printf(">>> ");
    scanf("%d", &op);
    puts("");
    
    switch(op) {
        case 1:
            float l1, l2, l3;
            puts("Entre com os lados dos triangulos");
            printf(">>> ");
            scanf("%f %f %f", &l1, &l2, &l3);
            int res = exercicio_1(l1, l2, l3);
            switch(res) {
                case 0:
                    puts("Os valores digitados nao configuram um triagulo valido.");
                    break;
                case 1:
                    puts("O triangulo eh equilatero.");
                    break;
                case 2:
                    puts("O triangulo eh isoceles.");
                    break;
                case 3:
                    puts("O triangulo eh escaleno.");
                    break;
                default:
                    puts("Algo de errado nao esta certo");
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            puts("Opcao invalida! Encerrando o programa...");
    }
}

int main() {
    //exercicio_1();
    //exercicio_2();
    //exercicio_3();
    exercicio_4();
}
