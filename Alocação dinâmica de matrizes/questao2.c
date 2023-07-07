//Questão 2:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int linhas, colunas, i, j;
    int **matriz;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Aloca memória dinamicamente para a matriz
    matriz = (int **)malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Solicita ao usuário que insira os elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprime a matriz na forma original
    printf("\nMatriz Original:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprime a matriz transposta
    printf("\nMatriz Transposta:\n");
    for (j = 0; j < colunas; j++) {
        for (i = 0; i < linhas; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada para a matriz
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
