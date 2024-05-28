#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ALUNOS 100

//  estrutura aluno
struct Aluno {
    int matricula;
    char nome[50];
    char curso[50];
    char endereco[100];
    bool ativo;
};

//  funções
void mostrarMenu();
void cadastrarAluno(struct Aluno alunos[], int *numAlunos);
void removerAluno(struct Aluno alunos[], int numAlunos);
void alterarCurso(struct Aluno alunos[], int numAlunos);
void alterarEndereco(struct Aluno alunos[], int numAlunos);
void relatorioAlunos(struct Aluno alunos[], int numAlunos);

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;

    do {
        mostrarMenu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                cadastrarAluno(alunos, &numAlunos);
                break;
            case 2:
                removerAluno(alunos, numAlunos);
                break;
            case 3:
                relatorioAlunos(alunos, numAlunos);
                break;
            case 4:
                alterarCurso(alunos, numAlunos);
                break;
            case 5:
                alterarEndereco(alunos, numAlunos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}


void mostrarMenu() {
    printf("Insira a opção desejada\n");
    printf("\n-------------Menu-----------------:\n");
    printf("1 -------------Cadastrar aluno------------\n");
    printf("2 -------------Remover aluno------------\n");
    printf("3 -------------Relatório de alunos------------\n");
    printf("4 -------------Alterar curso------------\n");
    printf("5 -------------Alterar endereço------------\n");
    printf("0 -------------Sair---------\n");
    // mostra o menu
}


void cadastrarAluno(struct Aluno alunos[], int *numAlunos) {
    if (*numAlunos < MAX_ALUNOS) {
        printf("Digite a matrícula: ");
        scanf("%d", &alunos[*numAlunos].matricula);
        printf("Digite o nome: ");
        scanf("%s", alunos[*numAlunos].nome);
        printf("Digite o curso: ");
        scanf("%s", alunos[*numAlunos].curso);
        printf("Digite o endereço: ");
        scanf("%s", alunos[*numAlunos].endereco);
        alunos[*numAlunos].ativo = true;
        (*numAlunos)++;
        printf("Aluno cadastrado com sucesso.\n");
    } else {
        printf("Limite de alunos atingido.\n");
    }
}
// cadastra um aluno


void removerAluno(struct Aluno alunos[], int numAlunos) {
    int matricula;
    printf("Digite a matrícula do aluno a ser removido: ");
    scanf("%d", &matricula);
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            alunos[i].ativo = false;
            printf("Aluno removido com sucesso.\n");
            return;
        }
    }
    printf("Aluno não encontrado.\n");
    //remove um aluno
}


void relatorioAlunos(struct Aluno alunos[], int numAlunos) {//exibir o relatório de alunos
    printf("\nRelatório de alunos:\n");
    printf("Matrícula\tNome\tCurso\tEndereço\n");
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].ativo) {
            printf("%d\t%s\t%s\t%s\n", alunos[i].matricula, alunos[i].nome, alunos[i].curso, alunos[i].endereco);
        }
    }
}


void alterarCurso(struct Aluno alunos[], int numAlunos) { //alterar o curso de um aluno
    int matricula;
    char novoCurso[50];
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o novo curso: ");
    scanf("%s", novoCurso);
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            strcpy(alunos[i].curso, novoCurso);
            printf("Curso alterado com sucesso.\n");
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}


void alterarEndereco(struct Aluno alunos[], int numAlunos) {
    int matricula;
    char novoEndereco[100];
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o novo endereço: ");
    scanf("%s", novoEndereco);
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            strcpy(alunos[i].endereco, novoEndereco);
            printf("Endereço alterado com sucesso.\n");
            return;
        }
        // altera endereço de um aluno
    }
    printf("Aluno não encontrado.\n");
}
