#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <uuid/uuid.h>

struct Cliente {
    char codigo[37];
    char nome[100];
    char telefone[30];
    char endereco[100];
} Cliente;

struct Funcionario {
    char codigo[37];
    char nome[100];
    char telefone[30];
    char cargo[50];
    int salario;
} Funcionario;

struct Estadia {
    char codigo[37];
    time_t data_entrada;
    time_t data_saida;
    int qtd_diarias;
    char codigo_cliente[100];
    char numero_quarto[100];
} Estadia;

struct Quarto {
    int numero_quarto;
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

time_t parse_date(char *str) {
    int day, month, year;
    char *token = strtok(str, "/");
    if (token != NULL) {
        day = atoi(token);
    }
    token = strtok(NULL, "/");
    if (token != NULL) {
        month = atoi(token);
    }
    token = strtok(NULL, "/");
    if (token != NULL) {
        year = atoi(token);
    }

    struct tm _date;
    _date.tm_year = year - 1900;
    _date.tm_mon = month - 1;
    _date.tm_mday = day;
    _date.tm_hour = -1;
    _date.tm_min = 0;
    _date.tm_sec = 0;
    _date.tm_isdst = 0;

    time_t date = mktime(&_date);
    return date;
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

void criar_estadia() {
    char *data_entrada = get_line("Data de entrada (DD/MM/AAAA): ");
    char *data_saida = get_line("Data de saida (DD/MM/AAAA): ");
    char *codigo_cliente = get_line("Entre com o codigo do cliente: ");
    char *numero_quarto = get_line("  [1] QUARTO_1\n  [2] QUARTO_2\n  [3] QUARTO_3\nEscolha o quarto: ");

    struct Estadia model;
    strcpy(model.codigo, generate_uuid());
    model.data_entrada = parse_date(data_entrada);
    model.data_saida = parse_date(data_saida);
    strcpy(model.codigo_cliente, codigo_cliente);
    strcpy(model.numero_quarto, numero_quarto);
    model.qtd_diarias = 2;

    FILE *file = fopen("db/estadia", "a");
    fprintf(file, "%s;%ld;%ld;%d;%s;%s\n", model.codigo, model.data_entrada, model.data_saida, model.qtd_diarias, model.codigo_cliente, model.numero_quarto);
    fclose(file);
}

const int DESOCUPADO = 0;
const int OCUPADO = 1;

int QTD_CLIENTES;
struct Cliente *CLIENTES;
int QTD_FUNCIONARIOS;
const struct Funcionario *FUNCIONARIOS;
int QTD_ESTADIAS;
const struct Estadia *ESTADIAS;
#define QTD_QUARTOS 10
const struct Quarto QUARTOS[QTD_QUARTOS] = {
    { 1, 1, 10000, DESOCUPADO },
    { 2, 2, 12000, DESOCUPADO },
    { 3, 4, 16000, DESOCUPADO },
    { 4, 6, 20000, DESOCUPADO },
    { 5, 4, 16000, DESOCUPADO },
    { 6, 2, 12000, DESOCUPADO },
    { 7, 2, 12000, DESOCUPADO },
    { 8, 2, 12000, DESOCUPADO },
    { 9, 2, 12000, DESOCUPADO },
    { 10, 1, 10000, DESOCUPADO }
};

void load_clientes() {
    FILE *file = fopen("db/cliente", "r");
    CLIENTES = malloc(10 * sizeof(struct Cliente));
    QTD_CLIENTES = 0;
    char codigo[37];
    char nome[100];
    char telefone[30];
    char endereco[100]; 
    while(true) {
        int a = fscanf(file, "%36[^;];%[^;];%[^;];%[^\n]\n", codigo, nome, telefone, endereco);
        if (a != 4) {
            break;
        }
        struct Cliente cliente;
        strcpy(cliente.codigo, codigo);
        strcpy(cliente.nome, nome);
        strcpy(cliente.telefone, telefone);
        strcpy(cliente.endereco, endereco);
        CLIENTES[QTD_CLIENTES++] = cliente;
    }
    fclose(file);
}

struct Estadia find_estadia(char *codigo_estadia) {

} 

void dar_baixa(char *codigo_estadia) {

}

int main() {
    load_clientes();
    for (int i = 0; i < QTD_CLIENTES; i++) {
        struct Cliente cliente = CLIENTES[i];
        printf("%d:  %s  *  %s  *  %s  *  %s\n", i, cliente.codigo, cliente.nome, cliente.telefone, cliente.endereco);
    }
}