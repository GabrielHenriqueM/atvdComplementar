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
    printf("Cadastrar outro funcionario? (S/N): ");
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
        printf("Funcionario %d:\n", numFuncionarios + 1);

        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[numFuncionarios].nome);

        printf("Cargo: ");
        scanf(" %[^\n]", funcionarios[numFuncionarios].cargo);

        printf("Salario base: ");
        scanf(" %lf", &funcionarios[numFuncionarios].salarioBase);

        printf("Beneficios: ");
        scanf(" %lf", &funcionarios[numFuncionarios].beneficios);

        printf("Descontos: ");
        scanf(" %lf", &funcionarios[numFuncionarios].descontos);

        funcionarios[numFuncionarios] = calcularSalarioLiquido(funcionarios[numFuncionarios]);

        printf("Funcionario cadastrado.\n");

        numFuncionarios++;
    }

    printf("\nDados dos funcionarios:\n");

    for (int i = 0; i < numFuncionarios; ++i) {
        printf("Funcionario %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salario liquido: %.2lf\n\n", funcionarios[i].salarioLiquido);
    }

    double totalSalarios = 0.0;

    for (int i = 0; i < numFuncionarios; ++i) {
        totalSalarios += funcionarios[i].salarioLiquido;
    }

    double mediaSalarial = totalSalarios / numFuncionarios;
    printf("Media salarial da loja: %.2lf\n", mediaSalarial);

    double maiorSalario = funcionarios[0].salarioLiquido;
    char nomeMaiorSalario[100];
    strcpy(nomeMaiorSalario, funcionarios[0].nome);

    for (int i = 1; i < numFuncionarios; ++i) {
        if (funcionarios[i].salarioLiquido > maiorSalario) {
            maiorSalario = funcionarios[i].salarioLiquido;
            strcpy(nomeMaiorSalario, funcionarios[i].nome);
        }
    }

    printf("Funcionario com o maior salario: %s (Salario: %.2lf)\n", nomeMaiorSalario, maiorSalario);

    return 0;
}
