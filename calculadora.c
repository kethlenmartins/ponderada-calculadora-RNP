#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 100

typedef struct {
    int valor;
} Operando;

typedef struct {
    char op;
} Operador;

typedef struct {
    Operando data[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *P){
    P->topo = -1;
}

int quantidadeElementos (Pilha *P){
    return P->topo+1;
}

int pilhaEstaVazia(Pilha *P){
    return P->topo == -1;
}

int inserirOperando (Pilha *P, Operando O){
    if (quantidadeElementos(P) == MAX)
        return -1;
    P->topo++;
    P->data[P->topo] = O;
    return 0;
}

int removerOperando (Pilha *P, Operando *O){
    if (quantidadeElementos(P) == 0)
        return -1;
    *O = P->data[P->topo];
    P->topo--;
    return 0;
}


int ehNumero(char *token) {
    if (token == NULL || *token == '\0') return 0;

    for (int i = 0; token[i] != '\0'; i++) {
        if (!(token[i] >= '0' && token[i] <= '9')) {
            return -1;        }
    }

    return 1;
}

int calcularResultado(char *input, Pilha *P){
    char *token = strtok(input, " ");

    while (token != NULL) {
        if (ehNumero(token)) {
            Operando op;
            op.valor = atoi(token);
            inserirOperando(P, op);
        } else {
            Operando a, b, r;

            if (removerOperando(P, &b) == -1 || removerOperando(P, &a) == -1) {
                printf("Erro: operandos insuficientes para o operador '%s'.\n", token);
                return 0;
            }

            switch (token[0]) {
                case '+': r.valor = a.valor + b.valor; break;
                case '-': r.valor = a.valor - b.valor; break;
                case '*': r.valor = a.valor * b.valor; break;
                case '/':
                    if (b.valor == 0) {
                        printf("Erro: divisão por zero!\n");
                        return 0;
                    }
                    r.valor = a.valor / b.valor; 
                    break;
                default:
                    printf("Operador inválido: %s\n", token);
                    return 0;
            }

            inserirOperando(P, r);
        }

        token = strtok(NULL, " ");
    }

    Operando resultadoFinal;
    if (removerOperando(P, &resultadoFinal) == -1) {
        printf("Erro: pilha vazia ao tentar obter resultado final.\n");
        return 0;
    }
    return resultadoFinal.valor;
}

int main() {
    Pilha Calculadora;
    inicializarPilha(&Calculadora);

    char input[200];
    printf("Digite os números e operadores separados por espaço:\n");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    int resultado = calcularResultado(input, &Calculadora);
    printf("O resultado é: %d\n", resultado);

    return 0;
}
