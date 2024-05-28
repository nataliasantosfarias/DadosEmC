#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Cliente {
    char nome[MAX_NAME_LENGTH];
    int idade;
    struct Cliente* prox;
} Cliente;

typedef struct Fila {
    Cliente* frente;
    Cliente* traseira;
} Fila;

void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->traseira = NULL;
}

int filaVazia(Fila* fila) {
    return fila->frente == NULL;
}

void enfileirar(Fila* fila, char* nome, int idade) {
    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    strcpy(novoCliente->nome, nome);
    novoCliente->idade = idade;
    novoCliente->prox = NULL;

    if (filaVazia(fila)) {
        fila->frente = novoCliente;
        fila->traseira = novoCliente;
    } else {
        fila->traseira->prox = novoCliente;
        fila->traseira = novoCliente;
    }
}

Cliente* desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        return NULL;
    }

    Cliente* clienteRemovido = fila->frente;
    fila->frente = fila->frente->prox;

    if (fila->frente == NULL) {
        fila->traseira = NULL;
    }

    return clienteRemovido;
}

void imprimirCliente(Cliente* cliente) {
    if (cliente != NULL) {
        printf("Cliente chamado: %s, Idade: %d\n", cliente->nome, cliente->idade);
        free(cliente);
    } else {
        printf("Nenhum cliente na fila.\n");
    }
}

void adicionarCliente(Fila* filaPreferencial, Fila* filaRegular) {
    char nome[MAX_NAME_LENGTH];
    int idade;

    printf("Nome do cliente: ");
    scanf("%s", nome);
    printf("Idade do cliente: ");
    scanf("%d", &idade);

    if (idade >= 60) {
        enfileirar(filaPreferencial, nome, idade);
    } else {
        enfileirar(filaRegular, nome, idade);
    }
}

void chamarCliente(Fila* filaPreferencial, Fila* filaRegular, int* preferencialProxima) {
    if (*preferencialProxima && !filaVazia(filaPreferencial)) {
        imprimirCliente(desenfileirar(filaPreferencial));
        *preferencialProxima = 0;
    } else if (!filaVazia(filaRegular)) {
        imprimirCliente(desenfileirar(filaRegular));
        *preferencialProxima = 1;
    } else if (!filaVazia(filaPreferencial)) {
        imprimirCliente(desenfileirar(filaPreferencial));
        *preferencialProxima = 0;
    } else {
        printf("Nenhum cliente na fila.\n");
    }
}

int main() {
    Fila filaPreferencial, filaRegular;
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaRegular);

    int preferencialProxima = 1; // 1 indica que a próxima chamada será da fila preferencial
    char opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar cliente\n");
        printf("2. Chamar cliente\n");
        printf("S. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarCliente(&filaPreferencial, &filaRegular);
                break;
            case '2':
                chamarCliente(&filaPreferencial, &filaRegular, &preferencialProxima);
                break;
            case 'S':
            case 's':
                printf("Saindo Graças a Deus...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}