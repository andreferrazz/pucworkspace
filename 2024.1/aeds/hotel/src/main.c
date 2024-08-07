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

struct QuartoList {
    int capacity;
    int size;
    struct Quarto *elements;
} QuartoList;

struct QuartoList *empty_quarto_list() {
    struct QuartoList *list = malloc(sizeof(struct QuartoList));
    list->capacity = 10;
    list->size = 0;
    list->elements = malloc(list->capacity * sizeof(struct Quarto));
    return list;
}

void add_quarto(struct QuartoList *list, struct Quarto element) {
    list->elements[list->size++] = element;
}

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
    FILE *file = fopen("db/quartos", "rb");
    QUARTOS = malloc(20 * sizeof(struct Quarto));
    QTD_QUARTOS = 0;
    while (true) {
        struct Quarto *quarto = malloc(sizeof(struct Quarto));
        int a = fread(quarto, sizeof(struct Quarto), 1, file);
        if (a == 0) {
            free(quarto);
            break;
        }
        QUARTOS[QTD_QUARTOS++] = *quarto;
    }
    fclose(file);
}

void load_clientes() {
    FILE *file = fopen("db/clientes", "rb");
    CLIENTES = malloc(20 * sizeof(struct Cliente));
    QTD_CLIENTES = 0;
    while (true) {
        struct Cliente *cliente = malloc(sizeof(struct Cliente));
        int a = fread(cliente, sizeof(struct Cliente), 1, file);
        if (a == 0) {
            free(cliente);
            break;
        }
        CLIENTES[QTD_CLIENTES++] = *cliente;
    }
    fclose(file);
}

void load_estadias() {
    FILE *file = fopen("db/estadias", "rb");
    ESTADIAS = malloc(20 * sizeof(struct Estadia));
    QTD_ESTADIAS = 0;
    while (true) {
        struct Estadia *estadia = malloc(sizeof(struct Estadia));
        int a = fread(estadia, sizeof(struct Estadia), 1, file);
        if (a == 0) {
            free(estadia);
            break;
        }
        ESTADIAS[QTD_ESTADIAS++] = *estadia;
    }
    fclose(file);
}

void load_funcionarios() {
    FILE *file = fopen("db/funcionarios", "rb");
    FUNCIONARIOS = malloc(20 * sizeof(struct Funcionario));
    QTD_FUNCIONARIOS = 0;
    while (true) {
        struct Funcionario *funcionario = malloc(sizeof(struct Funcionario));
        int a = fread(funcionario, sizeof(struct Funcionario), 1, file);
        if (a == 0) {
            free(funcionario);
            break;
        }
        FUNCIONARIOS[QTD_FUNCIONARIOS++] = *funcionario;
    }
    fclose(file);
}

void save_quartos() {
    FILE *file = fopen("db/quartos", "wb");
    for (int i = 0; i < QTD_QUARTOS; i++) {
        struct Quarto quarto = QUARTOS[i];
        fwrite(&quarto, sizeof(quarto), 1, file);
    }
    fclose(file);
}

void save_clientes() {
    FILE *file = fopen("db/clientes", "wb");
    for (int i = 0; i < QTD_CLIENTES; i++) {
        struct Cliente cliente = CLIENTES[i];
        fwrite(&cliente, sizeof(cliente), 1, file);
    }
    fclose(file);
}

void save_estadias() {
    FILE *file = fopen("db/estadias", "wb");
    for (int i = 0; i < QTD_ESTADIAS; i++) {
        struct Estadia estadia = ESTADIAS[i];
        fwrite(&estadia, sizeof(estadia), 1, file);
    }
    fclose(file);
}

void save_funcionarios() {
    FILE *file = fopen("db/funcionarios", "wb");
    for (int i = 0; i < QTD_FUNCIONARIOS; i++) {
        struct Funcionario funcionario = FUNCIONARIOS[i];
        fwrite(&funcionario, sizeof(funcionario), 1, file);
    }
    fclose(file);
}

struct Quarto *find_quarto(int numero_quarto) {
    for (int i = 0; i < QTD_QUARTOS; i++) {
        if (QUARTOS[i].numero_quarto == numero_quarto) {
            return &QUARTOS[i];
        }
    }
}

struct QuartoList *find_quartos_disponiveis(int qtd_hospedes, time_t data_entrada, time_t data_saida) {
    struct QuartoList *list = empty_quarto_list();
    
    for (int i = 0; i < QTD_QUARTOS; i++) {
        struct Quarto quarto = QUARTOS[i];
        bool is_available = true;

        for (int j = 0; j < QTD_ESTADIAS; j++) {
            struct Estadia e = ESTADIAS[j];
            if (e.numero_quarto == quarto.numero_quarto) {
                if (e.data_entrada >= data_entrada && e.data_entrada <= data_saida) {
                    is_available = false;
                    break;
                }

                if (e.data_saida >= data_entrada && e.data_saida <= data_saida) {
                    is_available = false;
                    break;
                }
            }
        }

        if (is_available && QUARTOS[i].qtd_hospedes >= qtd_hospedes) {
            add_quarto(list, QUARTOS[i]);
        }
    }

    return list;
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
    char *codigo_cliente = get_line("Entre com o codigo do cliente: ");
    int qtd_hospedes = atoi(get_line("Entre com a quantidade de hospedes: "));
    time_t data_entrada = parse_date(get_line("Data de entrada (DD/MM/AAAA): "));
    time_t data_saida = parse_date(get_line("Data de saida (DD/MM/AAAA): "));
    struct QuartoList *list = find_quartos_disponiveis(qtd_hospedes, data_entrada, data_saida);
    printf("\nQuartos\n\n");
    for (int i = 0; i < list->size; i++) {
        printf("    [ %d ] { qtd_hospedes: %d, preco_diaria: %.2f }\n", 
        list->elements[i].numero_quarto,
        list->elements[i].qtd_hospedes,
        list->elements[i].valor_diaria / 100.0);
    }
    int numero_quarto = atoi(get_line("\nEscolha um dos quartos acima: "));

    struct Estadia estadia;
    strcpy(estadia.codigo, generate_uuid());
    strcpy(estadia.codigo_cliente, codigo_cliente);
    estadia.data_entrada = data_entrada;
    estadia.data_saida = data_saida;
    estadia.numero_quarto = numero_quarto;
    estadia.qtd_diarias = (estadia.data_saida - estadia.data_entrada) / (60 * 60 * 24);
    ESTADIAS[QTD_ESTADIAS++] = estadia;
}

char *parse_cargo(int e) {
    switch (e) {
    case 1:
        return "CARGO_1";
        break;

    case 2:
        return "CARGO_2";
        break;

    case 3:
        return "CARGO_3";
        break;

    default:
        break;
    }
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
    strcpy(funcionario.cargo, parse_cargo(atoi(cargo)));
    funcionario.salario = (atof(salario) * 100);
    FUNCIONARIOS[QTD_FUNCIONARIOS++] = funcionario;
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
    printf("    [ 12 ] Mostrar pontos de fidelidade\n");
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

    case 12:
        printf("Entre com o codigo do cliente: ");
        scanf("%s", codigo);
        show_pontos_fidelidade(codigo);
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

    save_quartos();
    save_clientes();
    save_estadias();
    save_funcionarios();
}