#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

struct Cliente {
    char codigo[100];
    char nome[100];
    char telefone[30];
    char endereco[100];
} Cliente;

struct Funcionario {
    char codigo[100];
    char nome[100];
    char telefone[30];
    char cargo[50];
    int salario;
} Funcionario;

struct Estadia {
    char codigo[100];
    char data_entrada[100];
    char data_saida[100];
    int qtd_diarias;
    char telefone[30];
    char codigo_cliente[100];
    char numero_quarto[100];
} Estadia;

struct Quarto {
    char numero_quarto[100];
    int qtd_hospedes;
    int valor_diaria;
    int status;
} Quarto;

char *generate_uuid() {
    uuid_t uuid;
    uuid_generate(uuid);
    char *uuid_str = malloc(37 * sizeof(char));
    uuid_unparse_lower(uuid, uuid_str);
    return uuid_str;
}

char *get_line(char *text) {
    printf("%s", text);
    char *buffer = malloc(100 * sizeof(char));
    fgets(buffer, 100, stdin);
    int size = strlen(buffer);
    buffer[size - 1] = '\0';
    return buffer;
}

void criar_cliente() {
    char *nome = get_line("Entre com o nome: ");
    char *telefone = get_line("Entre com o telefone: ");
    char *endereco = get_line("Entre com o endereco: ");

    struct Cliente cliente;
    strcpy(cliente.codigo, generate_uuid());
    strcpy(cliente.nome, nome);
    strcpy(cliente.telefone, telefone);
    strcpy(cliente.endereco, endereco);

    FILE *file = fopen("db/cliente", "a");
    fprintf(file, "%s;%s;%s;%s\n", cliente.codigo, cliente.nome, cliente.telefone, cliente.endereco);
    fclose(file);
}

void criar_funcionario() {
    char *nome = get_line("Entre com o nome: ");
    char *telefone = get_line("Entre com o telefone: ");
    char *cargo = get_line("  [1] CARGO_1\n  [2] CARGO_2\n  [3] CARGO_3\nEscolha o cargo: ");
    char *salario = get_line("Entre com o salario: ");

    struct Funcionario model;
    strcpy(model.codigo, generate_uuid());
    strcpy(model.nome, nome);
    strcpy(model.telefone, telefone);
    strcpy(model.cargo, cargo);
    model.salario = (atof(salario) * 100);

    FILE *file = fopen("db/funcionario", "a");
    fprintf(file, "%s;%s;%s;%s;%d\n", model.codigo, model.nome, model.telefone, model.cargo, model.salario);
    fclose(file);
}

int main() {
    criar_funcionario();
}