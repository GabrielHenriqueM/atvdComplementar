#include <stdio.h>
#include <stdbool.h>

struct Conjunto {

    int n;
    int elementos[20];

};

struct Conjunto inicializarConjunto() {

    struct Conjunto conjunto;
    conjunto.n = 0;

    return conjunto;
}

struct Conjunto lerConjunto() {
    struct Conjunto conjunto;

    printf("Quantidade de elementos: ");
    scanf("%d", &conjunto.n);

    printf("Digite os elementos:\n");

    for (int i = 0; i < conjunto.n; i++) {

        scanf("%d", &conjunto.elementos[i]);
    }

    return conjunto;
}

void imprimirConjunto(struct Conjunto conjunto) {
    printf("Conjunto: { ");
    for (int i = 0; i < conjunto.n; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}

struct Conjunto uniaoConjuntos(struct Conjunto conjuntoA, struct Conjunto conjuntoB) {
    struct Conjunto resultado = inicializarConjunto();

    for (int i = 0; i < conjuntoA.n; i++) {
        resultado.elementos[resultado.n++] = conjuntoA.elementos[i];
    }

    for (int i = 0; i < conjuntoB.n; i++) {

        bool duplicado = false;

        for (int j = 0; j < resultado.n; j++) {
            if (conjuntoB.elementos[i] == resultado.elementos[j]) {

                duplicado = true;
                break;
            }
        }
        if (!duplicado) {
            resultado.elementos[resultado.n++] = conjuntoB.elementos[i];
        }
    }
    return resultado;
}

int main() {
    struct Conjunto conjuntoA, conjuntoB, resultado;

    conjuntoA = inicializarConjunto();
    conjuntoB = inicializarConjunto();
    resultado = inicializarConjunto();

    printf("Conjunto A:\n");
    conjuntoA = lerConjunto();

    printf("Conjunto B:\n");
    conjuntoB = lerConjunto();

    resultado = uniaoConjuntos(conjuntoA, conjuntoB);

    printf("Uniao dos conjuntos:\n");
    imprimirConjunto(resultado);

    return 0;
}
