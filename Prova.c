#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professor {
    char nome[30];
    char disciplina[30];
    float horas;
} Professor;

void preencheProfessor(Professor *Prof) {
    printf("Digite o nome do professor: ");
    scanf(" %[^\n]", Prof->nome);
    printf("Digite a carga horaria: ");
    scanf("%f", &Prof->horas);
    printf("Digite a disciplina: ");
    scanf(" %[^\n]", Prof->disciplina);
}

void imprimeProfessor(Professor *Prof) {
    printf("Nome do professor: %s, Carga Horária: %.2f, Disciplina: %s\n", Prof->nome, Prof->horas, Prof->disciplina);
}

int main() {
    Professor Prof;
    preencheProfessor(&Prof);
    imprimeProfessor(&Prof);

    return 0;
}

