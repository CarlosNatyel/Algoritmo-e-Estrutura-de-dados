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

void alteraHorasProfessor(Professor *Prof) {
    printf("Digite a nova carga horária: ");
    scanf("%f", &Prof->horas);
}

int main() {
    Professor Prof;
    preencheProfessor(&Prof);
    imprimeProfessor(&Prof);

    alteraHorasProfessor(&Prof);
    imprimeProfessor(&Prof);

    return 0;
}
//eu apenas tirei um erro de digitação no printf da linha 12 *

