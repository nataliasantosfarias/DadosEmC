#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_aluno {
    int matricula;
    char nome[100];
    char curso[100];
    struct tipo_aluno *prox;
} Aluno;

void iniciar(Aluno **cabeca) {
    *cabeca = NULL;
}

void insere(char nome[100], char curso[100], int matricula, Aluno **cabeca) {
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    strcpy(novo->curso, curso);
    novo->matricula = matricula;
    novo->prox = *cabeca;
    *cabeca = novo;
    printf("%d - Aluno teve sua insercao concluida!\n", matricula);
}

void imprime(Aluno **cabeca) {
    printf("\n\n========= RELATORIO DE ALUNOS =========\n");
    Aluno *p = *cabeca;
    while (p != NULL) {
        printf("%d\n", p->matricula);
        printf("%s\n", p->nome);
        printf("%s\n", p->curso);
        printf("====================\n");
        p = p->prox;
    }
}

Aluno* buscar(int matricula, Aluno **cabeca) {
    Aluno *p = *cabeca;
    while (p != NULL) {
        if (p->matricula == matricula) {
            printf("### Aluno encontrado ###\n");
            printf("%d\n", p->matricula);
            printf("%s\n", p->nome);
            printf("%s\n", p->curso);
            return p;
        }
        p = p->prox;
    }
    printf("Aluno nao encontrado na base!\n");
    return NULL;
}

Aluno* buscar_anterior(int matricula, Aluno **cabeca) {
    Aluno *p = *cabeca;
    Aluno *anterior = NULL;

    while (p != NULL && p->matricula != matricula) {
        anterior = p;
        p = p->prox;
    }

    if (p == NULL) {
        printf("Aluno nao encontrado na base!\n");
        return NULL;
    }

    return anterior;
}

int remover_elemento(int matricula, Aluno **cabeca) {
    Aluno *anterior = buscar_anterior(matricula, cabeca);

    if (anterior == NULL && (*cabeca)->matricula != matricula) {
        printf("Aluno nao encontrado na base!\n");
        return 0;
    }

    Aluno *delete;
    if (anterior == NULL) {
        delete = *cabeca;
        *cabeca = (*cabeca)->prox;
    } else {
        delete = anterior->prox;
        anterior->prox = delete->prox;
    }

    printf("Matricula %d removida com sucesso.\n", matricula);
    free(delete);
    return 1;
}

void ler_arquivo(Aluno **cabeca) {
    FILE *arquivo = fopen("database_alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[255];
    while (fgets(linha, sizeof(linha), arquivo)) {
        int matricula;
        char nome[100];
        char curso[100];

        sscanf(linha, "%d %s %[^\n]", &matricula, nome, curso);
        insere(nome, curso, matricula, cabeca);
    }

    fclose(arquivo);
}

void escrever_arquivo(Aluno *cabeca) {
    FILE *arquivo = fopen("database_alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Aluno *atual = cabeca;
    while (atual != NULL) {
        fprintf(arquivo, "%d %s %s\n", atual->matricula, atual->nome, atual->curso);
        atual = atual->prox;
    }

    fclose(arquivo);
}

int main() {
    Aluno *cabeca;
    iniciar(&cabeca);
    ler_arquivo(&cabeca);

    // Restante do seu código...

    escrever_arquivo(cabeca);

    return 0;
}
