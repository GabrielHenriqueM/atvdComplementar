#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data {
    int dia, mes, ano;
};

struct Cliente {
    char nome[100];
    struct Data dataNascimento;
    int idade;
    char sexo;
};

struct Cliente lerCliente() {
    struct Cliente cliente;

    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);

    printf("Informe o dia de nascimento: ");
    scanf(" %d", &cliente.dataNascimento.dia);

    printf("Informe o mes de nascimento: ");
    scanf(" %d", &cliente.dataNascimento.mes);

    printf("Informe o ano de nascimento: ");
    scanf(" %d", &cliente.dataNascimento.ano);

    cliente.idade = 2023 - cliente.dataNascimento.ano;

    printf("Informe o sexo do cliente: ");
    scanf(" %c", &cliente.sexo);

    return cliente;
}

void limparTela() {
    system("cls");
}

void imprimirCliente(struct Cliente cliente) {
    printf("Nome: %s\n", cliente.nome);
    printf("Data de Nascimento: %02d/%02d/%d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
    printf("Idade: %d\n", cliente.idade);
    printf("Sexo: %c\n", cliente.sexo);
}

int main() {
    struct Cliente clientes[50];

    int numeroClientes = 0;

    while (1) {

        printf("Menu:\n");
        printf("1- Cadastrar cliente\n");
        printf("2- Listar clientes\n");
        printf("3- Sair\n");



        int escolha;
        scanf("%d", &escolha);
        system("cls");

        switch (escolha) {

            case 1:
                if (numeroClientes < 50) {
                    clientes[numeroClientes] = lerCliente();
                    numeroClientes++;


                } else {
                    printf("Limite de clientes atingido.\n");
                }

                break;

            case 2:
                printf("\n");
                printf("Clientes cadastrados:\n");
                for (int i = 0; i < numeroClientes; i++) {
                    printf("Cliente %d:\n", i + 1);
                    imprimirCliente(clientes[i]);
                    printf("\n");
                }

                break;

            case 3:
                printf("Programa finalizado.\n");
                return 0;

            default:
                printf("Escolha inválida.\n");

                break;
        }
    }

    return 0;
}
