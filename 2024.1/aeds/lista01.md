# Lista de Exercícios 1

Parte 1 – Exercícios para serem entregues

Resolva os exercícios a seguir e entregue pelo CANVAS. Cada exercício deve conter um arquivo
no formato .C

1. Implemente um algoritmo que solicite ao usuário um número inteiro n (digitado) e
posteriormente o sistema mostra o sucessor de n (ex. se o usuário digitou 15, o sistema deverá
imprimir 16).

2. Implemente um algoritmo que solicita o valor de 3 notas (n1, n2 e n3) e depois mostra: a soma,
a média e o produto das notas.

3. Implemente um programa que leia dois números reais e armazene-os em duas variáveis (ex.:
A e B). Em seguida, troque dos valores das variáveis de forma que a primeira variável passe a ter
o valor da segunda, e vice-versa. Ao final, imprima os valores finais das variáveis.

4. Implemente um programa que leia a quantidade de eleitores de um município, o número de
votos brancos, nulos e válidos. Calcule e imprima o percentual de cada um dos tipos de votos
(brancos, nulos e válidos).

5. Implemente um programa que o usuário informa o valor a ser investido, uma taxa de juros
mensal a ser aplicada ao capital, e o número de meses que irá durar a aplicação. Ao final o
programa deverá mostrar:
• O valor total acumulado ao final período.
• O valor de juros rendidos.

6. Escreva um programa que receba 2 pontos cartesianos (x, y) e calcule a distância Euclidiana
entre eles.
𝑑 = √(𝑥2 − 𝑥1) 2 + (𝑦2 − 𝑦1) 2
Pontifícia Universidade Católica de Minas Gerais
Instituto de Ciências Exatas e Informática (ICEI)
Engenharia de Computação / Engenharia de Software
Disciplina: Algoritmos e Estruturas de Dados I

7. Implemente um algoritmo com as linhas a seguir e apresente no código-fonte uma explicação
detalhada, com suas palavras, do que acontece em cada uma das linhas:
Linha Comando Explicação
1 int a,b,c,d=1;
2 a = -2;
3 b = a*a;
4 c = d++;
5 d = c++ + 5;
6 d = ++c + 5;
7 printf ("%d %d %d %d", a, b, c, d);

Informações sobre cópias

As questões são individuais. Em caso de cópias de trabalho a pontuação será zero para os
autores originais e copiadores. Não serão aceitas justificativas como: “Fizemos o trabalho
juntos, por isso estão idênticos”.

Parte 2 – Exercícios para Treino – Revisão (não precisam ser entregues)
1. Implemente um algoritmo que receba a altura e peso de uma pessoa e calcule e o seu Índice
de Massa Corporal (IMC).
2. Implemente um algoritmo que converta uma temperatura Fahrenheit em grau Celsius:
𝐺𝑟𝑎𝑢𝑠 𝐶𝑒𝑙𝑠𝑖𝑢𝑠 = 5
9 ⋅ (𝐹𝑎ℎ𝑟𝑒𝑛ℎ𝑒𝑖𝑡 − 32)
Obs: Ao codificar o programa, cuidado com o uso do operador de divisão. Em C, um mesmo
operador é utilizado para divisão inteira e para divisão real – a diferença se dá pelos operandos.
Será executada uma divisão inteira se ambos os operandos forem valores inteiros, caso
contrário, uma divisão real será realizada.
3. Implemente um programa que leia um número inteiro com três dígitos (no formato CDU -
centena, dezena e unidade) e mostre o número invertido (no formato UDC).
4. Escreva um programa em C para que converta uma quantidade específica de dias em anos
(considerar apenas 365 dias), semanas e dias.
Ex.: 500 dias = 1 ano, 133 semanas e 2 dias
Parte 3 – Exercícios para Treino - Básicos (não precisam ser entregues)
Tipos de variáveis, entrada de dados e saída de dados
1. Elabore um programa que escreva as mensagens “Início do programa” e “Fim” na tela, uma
em cada linha, usando apenas um comando printf().
2. Escreva um programa que leia um número inteiro e depois o imprima.
3. Escreva um programa que leia um número inteiro e depois imprima a mensagem “Valor lido:”,
seguido do valor inteiro. Use apenas um comando printf().
4. Faça um programa que leia um número inteiro e depois o imprima usando o operador “%f”.
Veja o que aconteceu.
5. Faça um programa que leia um valor do tipo float e depois o imprima usando o operador
“%d”. Veja o que aconteceu.
6. Faça um programa que leia um valor do tipo double e depois o imprima na forma de notação
científica.
7. Elabore um programa que leia um caractere e depois o imprima como um valor inteiro.
8. Faça um programa que leia dois números inteiros e depois os imprima na ordem inversa em
que eles foram lidos.
9. Faça um programa que leia dois valores do tipo float. Use um único comando de leitura para
isso. Em seguida, imprima os valores lidos na ordem inversa em que eles foram lidos.
10. Elabore um programa que solicite ao usuário entrar com o valor do dia, mês e ano (inteiros).
Em seguida, imprima os valores lidos separados por uma barra (\).
11. Elabore um programa que contenha uma constante qualquer do tipo float. Use o comando
#define. Imprima essa constante.
12. Elabore um programa que contenha uma constante qualquer do tipo int. Use o comando
const. Imprima essa constante.
13. Faça um programa que leia um caractere do tipo char e depois o imprima entre aspas duplas.
Assim, se o caractere lido for a letra A, deverá ser impresso “A”.
14. Faça um programa que leia três caracteres do tipo char e depois os imprima um em cada linha.
Use um único comando printf() para isso.
15. Escreva um programa que leia três variáveis: char, int e float. Em seguida, imprima-as de três
maneiras diferentes: separadas por espaços, por uma tabulação horizontal e uma em cada
linha. Use um único comando printf() para cada operação de escrita das três variáveis.
Operações lógicas, aritméticas e relacionais
16. Faça um programa que leia um número inteiro e retorne seu antecessor e seu sucessor.
17. Faça um programa que leia um número real e imprima a quinta parte desse número.
18. Faça um programa que leia três valores inteiros e mostre sua soma.
19. Faça um programa que calcule o ano de nascimento de uma pessoa a partir de sua idade e do
ano atual.
20. Leia uma velocidade em km/h (quilômetros por hora) e apresente convertida em m/s (metros
por segundo). A fórmula de conversão é M = K/36, sendo K a velocidade em km/h e M em
m/s.
21. Faça um programa que leia um valor em reais e a cotação do dólar. Em seguida, imprima o
valor correspondente em dólares.
22. Leia um ângulo em graus e apresente-o convertido em radianos. A fórmula de conversão é R
= G * π/180, sendo G o ângulo em graus e R em radianos e π = 3.141592.
23. A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso, sendo
que: O primeiro ganhador receberá 46% do total. O segundo receberá 32% do total. O terceiro
receberá o restante. Calcule e imprima a quantia recebida por cada um dos ganhadores.
24. Leia a altura e o raio de um cilindro circular e imprima o volume desse cilindro. O volume de
um cilindro circular é calculado por meio da seguinte fórmula: 𝑣 = 𝜋 ⋅ 𝑟𝑎𝑖𝑜2 ⋅ 𝑎𝑙𝑡𝑢𝑟𝑎, em que
π = 3.141592.
25. Sejam a e b os catetos de um triângulo cuja hipotenusa h é obtida pela equação: ℎ =
√𝑎2 + 𝑏2. Faça um programa que leia os valores de a e b, e calcule o valor da hipotenusa
através da fórmula dada e imprima o resultado.
26. Faça um programa que converta uma letra maiúscula em letra minúscula. Use a tabela ASCII
para isso.