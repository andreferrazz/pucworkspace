#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
    int numero_quarto;
    int qtd_diarias;
    time_t data_entrada;
    time_t data_saida;
    char codigo_cliente[37];
} Estadia;

struct Quarto {
    int numero_quarto;
    int qtd_hospedes;
    int valor_diaria;
    int status;
} Quarto;

struct ClienteList {
    int capacity;
    int size;
    struct Cliente *elements;
} ClienteList;

struct ClienteList *empty_cliente_list() {
    struct ClienteList *list = malloc(sizeof(struct ClienteList));
    list->capacity = 10;
    list->size = 0;
    list->elements = malloc(list->capacity * sizeof(struct Cliente));
    return list;
}

void add_cliente(struct ClienteList *list, struct Cliente element) {
    list->elements[list->size++] = element;
}

struct EstadiaList {
    int capacity;
    int size;
    struct Estadia *elements;
} EstadiaList;

struct EstadiaList *empty_estadia_list() {
    struct EstadiaList *list = malloc(sizeof(struct EstadiaList));
    list->capacity = 10;
    list->size = 0;
    list->elements = malloc(list->capacity * sizeof(struct Estadia));
    return list;
}

void add_estadia(struct EstadiaList *list, struct Estadia element) {
    list->elements[list->size++] = element;
}

const int DESOCUPADO = 0;
const int OCUPADO = 1;

int QTD_CLIENTES;
struct Cliente *CLIENTES;
int QTD_FUNCIONARIOS;
struct Funcionario *FUNCIONARIOS;
int QTD_ESTADIAS;
struct Estadia *ESTADIAS;
int QTD_QUARTOS;
struct Quarto *QUARTOS;

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

void load_quartos() {
    FILE *file = fopen("db/quarto", "r");
    QUARTOS = malloc(10 * sizeof(struct Quarto));
    QTD_QUARTOS = 0;
    int numero_quarto;
    int qtd_hospedes;
    int valor_diaria;
    int status;
    while (true) {
        int a = fscanf(file, "%d;%d;%d;%d\n", &numero_quarto, &qtd_hospedes, &valor_diaria, &status);
        if (a != 4) {
            break;
        }
        struct Quarto quarto;
        quarto.numero_quarto = numero_quarto;
        quarto.qtd_hospedes = qtd_hospedes;
        quarto.valor_diaria = valor_diaria;
        quarto.status = status;
        QUARTOS[QTD_QUARTOS++] = quarto;
    }
    fclose(file);
}

void load_clientes() {
    FILE *file = fopen("db/cliente", "r");
    CLIENTES = malloc(10 * sizeof(struct Cliente));
    QTD_CLIENTES = 0;
    char codigo[37];
    char nome[100];
    char telefone[30];
    char endereco[100];
    while (true) {
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

void load_estadias() {
    FILE *file = fopen("db/estadia", "r");
    ESTADIAS = malloc(10 * sizeof(struct Estadia));
    QTD_ESTADIAS = 0;
    char codigo[37];
    int numero_quarto;
    int qtd_diarias;
    time_t data_entrada;
    time_t data_saida;
    char codigo_cliente[37];
    while (true) {
        int a = fscanf(file, "%36[^;];%d;%d;%ld;%ld;%36[^\n]\n", codigo, &numero_quarto, &qtd_diarias, &data_entrada,
                       &data_saida, codigo_cliente);
        if (a != 6) {
            break;
        }
        struct Estadia estadia;
        strcpy(estadia.codigo, codigo);
        estadia.numero_quarto = numero_quarto;
        estadia.qtd_diarias = qtd_diarias;
        estadia.data_entrada = data_entrada;
        estadia.data_saida = data_saida;
        strcpy(estadia.codigo_cliente, codigo_cliente);
        ESTADIAS[QTD_ESTADIAS++] = estadia;
    }
    fclose(file);
}

void load_funcionarios() {
    FILE *file = fopen("db/funcionario", "r");
    FUNCIONARIOS = malloc(10 * sizeof(struct Funcionario));
    QTD_FUNCIONARIOS = 0;
    char codigo[37];
    char nome[100];
    char telefone[30];
    char cargo[50];
    int salario;
    while (true) {
        int a = fscanf(file, "%36[^;];%[^;];%[^;];%[^;];%d\n", codigo, nome, telefone, cargo, &salario);
        if (a != 5) {
            break;
        }
        struct Funcionario funcionario;
        strcpy(funcionario.codigo, codigo);
        strcpy(funcionario.nome, nome);
        strcpy(funcionario.telefone, telefone);
        strcpy(funcionario.cargo, cargo);
        funcionario.salario = salario;
        FUNCIONARIOS[QTD_FUNCIONARIOS++] = funcionario;
    }
    fclose(file);
}

void save_clientes() {
    FILE *file = fopen("db/cliente", "w");
    for (int i = 0; i < QTD_CLIENTES; i++) {
        struct Cliente cliente = CLIENTES[i];
        fprintf(file, "%s;%s;%s;%s\n", cliente.codigo, cliente.nome, cliente.telefone, cliente.endereco);
    }
    fclose(file);
}

void save_estadias() {
    FILE *file = fopen("db/estadia", "w");
    for (int i = 0; i < QTD_ESTADIAS; i++) {
        struct Estadia estadia = ESTADIAS[i];
        fprintf(file, "%s;%d;%d;%ld;%ld;%s\n", estadia.codigo, estadia.numero_quarto, estadia.qtd_diarias,
                estadia.data_entrada, estadia.data_saida, estadia.codigo_cliente);
    }
    fclose(file);
}

void save_funcionarios() {
    FILE *file = fopen("db/funcionario", "w");
    for (int i = 0; i < QTD_FUNCIONARIOS; i++) {
        struct Funcionario funcionario = FUNCIONARIOS[i];
        fprintf(file, "%s;%s;%s;%s;%d\n", funcionario.codigo, funcionario.nome, funcionario.telefone, funcionario.cargo,
                funcionario.salario);
    }
    fclose(file);
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
    CLIENTES[QTD_CLIENTES++] = cliente;
}

void criar_estadia() {
    char *data_entrada = get_line("Data de entrada (DD/MM/AAAA): ");
    char *data_saida = get_line("Data de saida (DD/MM/AAAA): ");
    char *codigo_cliente = get_line("Entre com o codigo do cliente: ");
    // TODO: get quartos disponiveis
    char *numero_quarto = get_line("  [1] QUARTO_1\n  [2] QUARTO_2\n  [3] QUARTO_3\nEscolha o quarto: ");

    struct Estadia estadia;
    strcpy(estadia.codigo, generate_uuid());
    estadia.numero_quarto = atoi(numero_quarto);
    estadia.data_entrada = parse_date(data_entrada);
    estadia.data_saida = parse_date(data_saida);
    estadia.qtd_diarias = (estadia.data_saida - estadia.data_entrada) / (60 * 60 * 24);
    strcpy(estadia.codigo_cliente, codigo_cliente);
    ESTADIAS[QTD_ESTADIAS++] = estadia;
}

void criar_funcionario() {
    char *nome = get_line("Entre com o nome: ");
    char *telefone = get_line("Entre com o telefone: ");
    char *cargo = get_line("  [1] CARGO_1\n  [2] CARGO_2\n  [3] CARGO_3\nEscolha o cargo: ");
    char *salario = get_line("Entre com o salario: ");

    struct Funcionario funcionario;
    strcpy(funcionario.codigo, generate_uuid());
    strcpy(funcionario.nome, nome);
    strcpy(funcionario.telefone, telefone);
    strcpy(funcionario.cargo, cargo);
    funcionario.salario = (atof(salario) * 100);
    FUNCIONARIOS[QTD_FUNCIONARIOS++] = funcionario;
}

struct Quarto *find_quarto(int numero_quarto) {
    for (int i = 0; i < QTD_QUARTOS; i++) {
        if (QUARTOS[i].numero_quarto == numero_quarto) {
            return &QUARTOS[i];
        }
    }
}

struct Cliente *find_cliente(char *codigo_cliente) {
    for (int i = 0; i < QTD_CLIENTES; i++) {
        if (strcmp(CLIENTES[i].codigo, codigo_cliente) == 0) {
            return &CLIENTES[i];
        }
    }
}

struct Estadia *find_estadia(char *codigo_estadia) {
    for (int i = 0; i < QTD_ESTADIAS; i++) {
        if (strcmp(ESTADIAS[i].codigo, codigo_estadia) == 0) {
            return &ESTADIAS[i];
        }
    }
}

struct EstadiaList *find_estadias_by_cliente(char *codigo_cliente) {
    struct EstadiaList *list = empty_estadia_list();
    
    for (int i = 0; i < QTD_ESTADIAS; i++) {
        if (strcmp(ESTADIAS[i].codigo_cliente, codigo_cliente) == 0) {
            add_estadia(list, ESTADIAS[i]);
        }
    }

    return list;
}

struct Funcionario *find_funcionario(char *codigo_funcionario) {
    for (int i = 0; i < QTD_FUNCIONARIOS; i++) {
        if (strcmp(FUNCIONARIOS[i].codigo, codigo_funcionario) == 0) {
            return &FUNCIONARIOS[i];
        }
    }
}

void print_quarto(struct Quarto *quarto) {
    printf(
        "Quarto{ %d  *  %d  *  %d  *  %d }\n", 
        quarto->numero_quarto, 
        quarto->qtd_hospedes,
        quarto->valor_diaria, 
        quarto->status
    );
}

void print_cliente(struct Cliente *cliente) {
    printf(
        "Cliente{ %s  *  %s  *  %s  *  %s }\n", 
        cliente->codigo, 
        cliente->nome, 
        cliente->telefone,
        cliente->endereco
    );
}

void print_estadia(struct Estadia *estadia) {
    printf(
        "Estadia{ %s  *  %d  *  %d  *  %ld  *  %ld  *  %s }\n", 
        estadia->codigo, 
        estadia->numero_quarto,
        estadia->qtd_diarias, 
        estadia->data_entrada, 
        estadia->data_saida, 
        estadia->codigo_cliente
    );
}

void print_funcionario(struct Funcionario *funcionario) {
    printf(
        "Funcionario{ %s  *  %s  *  %s  *  %s  *  %d }\n", 
        funcionario->codigo, 
        funcionario->nome,
        funcionario->telefone, 
        funcionario->cargo, 
        funcionario->salario
    );
}

void show_quartos() {
    printf("\n******** QUARTOS ********\n\n");
    for(int i = 0; i < QTD_QUARTOS; i++) {
        print_quarto(&QUARTOS[i]);
    }
    printf("\n*************************\n");
}

void show_clientes() {
    printf("\n******** CLIENTES ********\n\n");
    for(int i = 0; i < QTD_CLIENTES; i++) {
        print_cliente(&CLIENTES[i]);
    }
    printf("\n**************************\n");
}

void show_estadias() {
    printf("\n******** ESTADIAS ********\n\n");
    for(int i = 0; i < QTD_ESTADIAS; i++) {
        print_estadia(&ESTADIAS[i]);
    }
    printf("\n**************************\n");
}

void show_funcionarios() {
    printf("\n******** FUNCIONARIOS ********\n\n");
    for(int i = 0; i < QTD_FUNCIONARIOS; i++) {
        print_funcionario(&FUNCIONARIOS[i]);
    }
    printf("\n******************************\n");
}

void dar_baixa(char *codigo_estadia) {
    struct Estadia *estadia = find_estadia(codigo_estadia);

    struct Quarto *quarto = find_quarto(estadia->numero_quarto);

    quarto->status = DESOCUPADO;
    float total = (estadia->qtd_diarias * quarto->valor_diaria) / 100.0;
    printf("Total a ser pago: R$ %.2f\n", total);
}

void show_pontos_fidelidade(char *codigo_cliente) {
    struct EstadiaList *estadias = find_estadias_by_cliente("70708bd1-8539-400d-86c6-355db85362b2");
    int diarias = 0;
    for (int i = 0; i < estadias->size; i++) {
        diarias += estadias->elements[i].qtd_diarias;
    }
    int pontos = diarias * 10;
    printf("Pontos de fidelidade acumulados: %d\n", pontos);
}

int menu() {
    int opcao;
    printf("\nEscolha uma das opcoes abaixo:\n");
    printf("    [ 0 ] SAIR\n");
    printf("    [ 1 ] Buscar quarto pelo numero\n");
    printf("    [ 2 ] Buscar cliente pelo codigo\n");
    printf("    [ 3 ] Buscar estadia pelo codigo\n");
    printf("    [ 4 ] Buscar funcionario pelo codigo\n");
    printf("    [ 5 ] Listas todos os quartos\n");
    printf("    [ 6 ] Listas todos os clientes\n");
    printf("    [ 7 ] Listas todos as estadias\n");
    printf("    [ 8 ] Listas todos os funcionarios\n");
    printf("    [ 9 ] Cadastrar cliente\n");
    printf("    [ 10 ] Cadastrar estadia\n");
    printf("    [ 11 ] Cadastrar funcionario\n");
    scanf("%d", &opcao);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    return opcao;
}

void run_action(int action) {
    int n; 
    char codigo[37];
    switch (action) {
    case 1:
        printf("Entre com o numero do quarto: ");
        scanf("%d", &n);
        print_quarto(find_quarto(n));
        break;
    
    case 2:
        printf("Entre com o codigo do cliente: ");
        scanf("%s", codigo);
        print_cliente(find_cliente(codigo));
        break;

    case 3:
        printf("Entre com o codigo da estadia: ");
        scanf("%s", codigo);
        print_estadia(find_estadia(codigo));
        break;

    case 4:
        printf("Entre com o codigo do funcionario: ");
        scanf("%s", codigo);
        print_funcionario(find_funcionario(codigo));
        break;
    
    case 5:
        show_quartos();
        break;
    
    case 6:
        show_clientes();
        break;
    
    case 7:
        show_estadias();
        break;
    
    case 8:
        show_funcionarios();
        break;
    
    case 9:
        criar_cliente();
        break;
    
    case 10:
        criar_estadia();
        break;
    
    case 11:
        criar_funcionario();
        break;
    
    default:
        printf("Acao invalida!\n");
    }
}

int main() {
    load_quartos();
    load_clientes();
    load_estadias();
    load_funcionarios();

    while (true) {
        int action = menu();
        if (action == 0) {
            break;
        }
        run_action(action);
    }

    // print_quarto(find_quarto(1));
    // print_cliente(find_cliente("fd01a1a1-1b08-4434-9cdc-f4d54112e582"));
    // print_estadia(find_estadia("a5540727-681c-4cb4-bae8-d3c3b8780d7a"));
    // print_funcionario(find_funcionario("7ea66bde-26a2-444a-8ca0-21daaf8b035a"));
    // criar_cliente();
    // criar_estadia();
    // criar_funcionario();
    // dar_baixa("901e8c2d-5f6a-439b-9ff3-c818c23e824e");
    // show_pontos_fidelidade("70708bd1-8539-400d-86c6-355db85362b2");
    save_clientes();
    save_estadias();
    save_funcionarios();
}