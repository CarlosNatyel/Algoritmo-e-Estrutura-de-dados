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

    // Solicita ao usuário que digite o número de questões do teste
    printf("Digite o número de questões: ");
    scanf("%d", &numQuestoes);

    // Verifica se o número de questões está dentro do intervalo válido
    if (numQuestoes <= 0 || numQuestoes > MAX_QUESTOES) {
        printf("Número de questões inválido.\n");
        return 1;
    }

    // Solicita ao usuário que digite o gabarito da prova
    printf("Digite o gabarito da prova (uma sequência de %d caracteres): ", numQuestoes);
    scanf(" %[^\n]", gabarito);

    // Verifica se o tamanho do gabarito coincide com o número de questões
    if (strlen(gabarito) != numQuestoes) {
        printf("Gabarito inválido.\n");
        return 1;
    }

    // Loop para cada aluno, obtendo suas respostas e calculando suas notas
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);

        // Solicita ao usuário que digite as respostas do aluno
        printf("Digite as respostas do aluno (uma sequência de %d caracteres): ", numQuestoes);
        scanf(" %[^\n]", respostas[i]);

        // Verifica se o tamanho das respostas do aluno coincide com o número de questões
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

        // Verifica se o aluno foi aprovado e atualiza o número de alunos aprovados
        if (nota >= 6) {
            numAprovados++;
        }
    }

    // Exibe as notas de todos os alunos
    printf("\n--- Notas dos Alunos ---\n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }

    // Calcula e exibe a porcentagem de alunos aprovados
    float porcentagemAprovados = (float)numAprovados / MAX_ALUNOS * 100.0;
    printf("\nPorcentagem de Aprovados: %.2f%%\n", porcentagemAprovados);

    return 0;
}
