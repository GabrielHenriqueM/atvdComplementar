#include <stdio.h>
#include <string.h>


struct Funcionario {

    char nome[100];
    char cargo[100];
    double salarioBase;
    double beneficios;
    double descontos;
    double salarioLiquido;
};

struct Funcionario calcularSalarioLiquido(struct Funcionario funcionario) {
    funcionario.salarioLiquido = funcionario.salarioBase + funcionario.beneficios - funcionario.descontos;
    return funcionario;
}


int cadastrarOutroFuncionario() {

    char resposta;
    printf("Cadastrar outro funcion�rio? (S/N): ");
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's') {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    struct Funcionario funcionarios[10];
    int numFuncionarios = 0;

    while (numFuncionarios < 10 && cadastrarOutroFuncionario()) {
        printf("Funcion�rio %d:\n", numFuncionarios + 1);

        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[numFuncionarios].nome);

        printf("Cargo: ");
        scanf(" %[^\n]", funcionarios[numFuncionarios].cargo);

        printf("Sal�rio base: ");
        scanf(" %lf", &funcionarios[numFuncionarios].salarioBase);

        printf("Benef�cios: ");
        scanf(" %lf", &funcionarios[numFuncionarios].beneficios);

        printf("Descontos: ");
        scanf(" %lf", &funcionarios[numFuncionarios].descontos);

        funcionarios[numFuncionarios] = calcularSalarioLiquido(funcionarios[numFuncionarios]);

        printf("Funcion�rio cadastrado.\n");



        numFuncionarios++;
    }

    printf("\nDados dos funcion�rios:\n");

    for (int i = 0; i < numFuncionarios; ++i) {

        printf("Funcion�rio %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Sal�rio l�quido: %.2lf\n\n", funcionarios[i].salarioLiquido);
    }

    double totalSalarios = 0.0;

    for (int i = 0; i < numFuncionarios; ++i) {
        totalSalarios += funcionarios[i].salarioLiquido;
    }

    double mediaSalarial = totalSalarios / numFuncionarios;
    printf("M�dia salarial da loja: %.2lf\n", mediaSalarial);

    double maiorSalario = funcionarios[0].salarioLiquido;
    char nomeMaiorSalario[100];
    strcpy(nomeMaiorSalario, funcionarios[0].nome);

    for (int i = 1; i < numFuncionarios; ++i) {

        if (funcionarios[i].salarioLiquido > maiorSalario) {
            maiorSalario = funcionarios[i].salarioLiquido;
            strcpy(nomeMaiorSalario, funcionarios[i].nome);
        }
    }

    printf("Funcion�rio com o maior sal�rio: %s (Sal�rio: %.2lf)\n", nomeMaiorSalario, maiorSalario);

    return 0;
}
