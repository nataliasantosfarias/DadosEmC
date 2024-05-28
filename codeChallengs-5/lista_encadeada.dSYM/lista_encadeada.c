#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_aluno {
    int matricula;
    char nome[100];
    char curso[100];
} Aluno;

void ler_arquivo(Aluno alunos[], int *total_alunos) {/* A função ler_arquivo() foi modificada para ler os dados do arquivo e preencher um array de structs Aluno.*/
    FILE *arquivo = fopen("database_alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d %[^\n] %[^\n]", &alunos[*total_alunos].matricula, alunos[*total_alunos].nome, alunos[*total_alunos].curso) != EOF) {
        (*total_alunos)++;
    }

    fclose(arquivo);
}

void ordenar_alunos(Aluno alunos[], int total_alunos) { /*A função ordenar_alunos() foi modificada para ordenar esse array de structs por ordem alfabética usando a função strcmp() da biblioteca string.h.*/
    int trocou = 1;
    while (trocou) {
        trocou = 0;
        for (int i = 0; i < total_alunos - 1; i++) {
            if (strcmp(alunos[i].nome, alunos[i + 1].nome) > 0) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[i + 1];
                alunos[i + 1] = temp;
                trocou = 1;
            }
        }
    }
}

void imprimir_alunos(Aluno alunos[], int total_alunos) {  /* Adicionamos uma função imprimir_alunos() para imprimir os alunos ordenados.*/
    printf("\n=========================== RELATORIO DE ALUNOS =============================\n");
    for (int i = 0; i < total_alunos; i++) {
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Curso: %s\n", alunos[i].curso);
        printf("============================================================================\n");
    }
}

int main() {
    Aluno alunos[100]; // Definindo um array de alunos com capacidade para 100 alunos
    int total_alunos = 0;

    ler_arquivo(alunos, &total_alunos);

    ordenar_alunos(alunos, total_alunos);

    imprimir_alunos(alunos, total_alunos);

    return 0;
}


/******************************************************************************

O código lê o arquivo, preenche o array de alunos, ordena-o por ordem alfabética e imprime os alunos ordenados.
usar o cabeçalho string.h e sua função de comparação (strcmp()).








*******************************************************************************/