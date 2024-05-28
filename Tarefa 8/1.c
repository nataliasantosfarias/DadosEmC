#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alunos: [Ana Paula Sampaio], [Natália Farias Santos]

typedef struct tipo_carro {
    char nome[100];
    char cpf[12];
    char marca[50];
    char modelo[50];
    char placa[8];
    struct tipo_carro *proximo;
} Carro;

typedef struct {
    Carro *topo;
} Pilha;

void iniciar(Pilha *pilha) {
    pilha->topo = NULL;
}

void adicionar_carro(char nome[100], char cpf[12], char marca[50], char modelo[50], char placa[8], Pilha *pilha) {
    Carro *novo = (Carro *)malloc(sizeof(Carro));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    strcpy(novo->marca, marca);
    strcpy(novo->modelo, modelo);
    strcpy(novo->placa, placa);
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    printf("%s - O seu carro foi adicionado na pilha!\n", nome);
}

void remover_carro(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia!\n");
        return;
    }

    Carro *remover = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    printf("Carro removido: %s, Placa: %s\n", remover->nome, remover->placa);
    free(remover);
}

void listar_carros(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia!\n");
        return;
    }

    Carro *atual = pilha->topo;
    printf("\n\n========= PILHA =========\n");
    while (atual != NULL) {
        printf("Nome: %s, CPF: %s, Marca: %s, Modelo: %s, Placa: %s\n", atual->nome, atual->cpf, atual->marca, atual->modelo, atual->placa);
        atual = atual->proximo;
    }
    printf("========= PILHA =========\n");
}

int main() {
    Pilha vaga1, vaga2;
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

        if (opcao == 0) {
            printf("Você escolheu sair! Obrigado, volte sempre!\n");
            break;
        }

        if (opcao >= 1 && opcao <= 3) {
            printf("Escolha a vaga (1 ou 2): ");
            scanf("%d", &vaga);
            Pilha *pilha_selecionada = (vaga == 1) ? &vaga1 : &vaga2;

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
                    adicionar_carro(nome, cpf, marca, modelo, placa, pilha_selecionada);
                    break;
                case 2:
                    remover_carro(pilha_selecionada);
                    break;
                case 3:
                    listar_carros(pilha_selecionada);
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
