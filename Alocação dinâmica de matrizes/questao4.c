//Questão 4:
#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 100
#define TAM_NOME 100

int main(void) {
    int numPessoas, i;
    char **nomes;
    int *idades;

    printf("Digite o número de pessoas: ");
    scanf("%d", &numPessoas);

    if (numPessoas > MAX_PESSOAS) {
        printf("Número de pessoas excede o limite máximo.\n");
        return 1;
    }

    // Aloca memória dinamicamente para os nomes
    nomes = (char **)malloc(numPessoas * sizeof(char *));
    for (i = 0; i < numPessoas; i++) {
        nomes[i] = (char *)malloc(TAM_NOME * sizeof(char));
    }

    // Aloca memória dinamicamente para as idades
    idades = (int *)malloc(numPessoas * sizeof(int));

    // Solicita ao usuário que digite o nome e a idade de cada pessoa
    for (i = 0; i < numPessoas; i++) {
        printf("\nPessoa %d\n", i + 1);
        printf("Nome completo: ");
        scanf(" %[^\n]", nomes[i]);
        printf("Idade: ");
        scanf("%d", &idades[i]);
    }

    // Exibe os nomes e idades armazenados
    printf("\nNomes e Idades Armazenados:\n");
    for (i = 0; i < numPessoas; i++) {
        printf("Nome: %s\tIdade: %d\n", nomes[i], idades[i]);
    }

    // Libera a memória alocada para os nomes
    for (i = 0; i < numPessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
