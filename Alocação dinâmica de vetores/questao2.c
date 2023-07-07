//Questão 2:
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTOES 10
#define MAX_ALUNOS 10

int main(void) {
    int numQuestoes, i, j;
    char gabarito[MAX_QUESTOES + 1];
    char respostas[MAX_ALUNOS][MAX_QUESTOES + 1];
    float notas[MAX_ALUNOS];
    int numAprovados = 0;

    printf("Digite o número de questões: ");
    scanf("%d", &numQuestoes);

    if (numQuestoes <= 0 || numQuestoes > MAX_QUESTOES) {
        printf("Número de questões inválido.\n");
        return 1;
    }

    printf("Digite o gabarito da prova (uma sequência de %d caracteres): ", numQuestoes);
    scanf(" %[^\n]", gabarito);

    if (strlen(gabarito) != numQuestoes) {
        printf("Gabarito inválido.\n");
        return 1;
    }

    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);

        printf("Digite as respostas do aluno (uma sequência de %d caracteres): ", numQuestoes);
        scanf(" %[^\n]", respostas[i]);

        if (strlen(respostas[i]) != numQuestoes) {
            printf("Respostas inválidas.\n");
            return 1;
        }

        // Calcula a nota do aluno
        float nota = 0;
        for (j = 0; j < numQuestoes; j++) {
            if (respostas[i][j] == gabarito[j]) {
                nota += 10.0 / numQuestoes;
            }
        }

        notas[i] = nota;

        // Verifica se o aluno foi aprovado
        if (nota >= 6) {
            numAprovados++;
        }
    }

    printf("\n--- Notas dos Alunos ---\n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }

    float porcentagemAprovados = (float)numAprovados / MAX_ALUNOS * 100.0;
    printf("\nPorcentagem de Aprovados: %.2f%%\n", porcentagemAprovados);

    return 0;
