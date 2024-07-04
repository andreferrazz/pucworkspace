#include <iostream>

class Ingrediente {
    char nome[100];
    double quantidade;
    char unidade[100];

    public:
        char *getNome() {
            return nome;
        }
        void setNome(char nome[100]) {
            
        }
        double getQuantidade() {
            return quantidade;
        }
        char *getUnidade() {
            return unidade;
        }
};

int main() {
    std::cout << "Hello World!";

    Ingrediente i;
}
