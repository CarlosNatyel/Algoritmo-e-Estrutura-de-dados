#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

int main() {
    
    FILE *arquivo;
    char nomeArquivo[50];
    int d;
    
    printf("Digite o nome do arquivo: ");
    scanf(" %[^\n]", nomeArquivo);
    
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("Digite o numero de alunos: ");
    scanf("%d", &d);
    Aluno *aluno = (Aluno*) malloc(d*sizeof(Aluno));
    
    int e; 
    for (e = 0; e < d; e++) {
        printf("Digite o nome do aluno: ");
        scanf("%s", aluno[e].nome);
        printf("Digite a nota 1 do aluno: ");
        scanf("%f", &aluno[e].nota1);
        printf("Digite a nota 2 do aluno: ");
        scanf("%f", &aluno[e].nota2);
        printf("Digite a nota 3 do aluno: ");
        scanf("%f", &aluno[e].nota3);

        fprintf(arquivo, "%s\t%f\t%f\t%f\n", aluno[e].nome, aluno[e].nota1, aluno[e].nota2, aluno[e].nota3);
    }

    fclose(arquivo);
}
