#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desenvolvido por: [Seu Nome], [Outro Nome]

typedef struct tipo_carro {
    char nome[100];
    char cpf[12];
    char marca[50];
    char modelo[50];
    char placa[8];
    struct tipo_carro *proximo;
} Carro;

typedef struct {
    Carro *inicio;
    Carro *fim;
} Fila;

void iniciar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

//função adicionar
void adicionar_carro(char nome[100], char cpf[12], char marca[50], char modelo[50], char placa[8], Fila *fila) {
    Carro *novo = (Carro *)malloc(sizeof(Carro));
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    strcpy(novo->marca, marca);
    strcpy(novo->modelo, modelo);
    strcpy(novo->placa, placa);
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    printf("%s - O seu carro adicionado na fila!\n", nome);
}

//função remover
void remover_carro(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila está vazia!\n");
        return;
    }

    Carro *remover = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    printf("Carro removido: %s, Placa: %s\n", remover->nome, remover->placa);
    free(remover);
    // a função free é usada para liberar a memória
}

// usada para listar os carros
void listar_carros(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila está vazia!\n");
        return;
    }

    Carro *atual = fila->inicio;
    printf("\n\n========= FILA =========\n");
    while (atual != NULL) {
        printf("Nome: %s, CPF: %s, Marca: %s, Modelo: %s, Placa: %s\n", atual->nome, atual->cpf, atual->marca, atual->modelo, atual->placa);
        atual = atual->proximo;
    }
    printf("========= FILA =========\n");
}

int main() {
    Fila vaga1, vaga2;
    iniciar(&vaga1);
    iniciar(&vaga2);

    int opcao, vaga;
    char nome[100], cpf[12], marca[50], modelo[50], placa[8];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar carro na vaga (1 ou 2)\n");
        printf("2. Remover carro da vaga (1 ou 2)\n");
        printf("3. Listar carros da vaga (1 ou 2)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) { // Se opção for 0 PARE;
            printf("Você escolheu sair!, \n obrigada volte sempre!");
            break;
        }

        if (opcao >= 1 && opcao <= 3) { // Se condição maior ou igual 1, e menor ou igual à 3...
            printf("Escolha a vaga (1 ou 2): ");
            scanf("%d", &vaga);
            Fila *fila_selecionada = (vaga == 1) ? &vaga1 : &vaga2;

            switch (opcao) {
                case 1:
                    printf("Digite o nome do proprietário: ");
                    scanf(" %[^\n]", nome);
                    printf("Digite o CPF do proprietário: ");
                    scanf(" %s", cpf);
                    printf("Digite a marca do carro: ");
                    scanf(" %[^\n]", marca);
                    printf("Digite o modelo do carro: ");
                    scanf(" %[^\n]", modelo);
                    printf("Digite a placa do carro: ");
                    scanf(" %s", placa);
                    adicionar_carro(nome, cpf, marca, modelo, placa, fila_selecionada);
                    break;
                case 2:
                    remover_carro(fila_selecionada);
                    break;
                case 3:
                    listar_carros(fila_selecionada);
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
