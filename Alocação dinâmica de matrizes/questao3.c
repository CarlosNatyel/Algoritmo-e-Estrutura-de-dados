//Questão 3:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, i, j;
    int** matriz;

    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n);

    // Aloca memória dinamicamente para a matriz
    matriz = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }

    // Preenche a matriz com números aleatórios entre 1 e 100
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    // Exibe a matriz resultante
    printf("\nMatriz Resultante:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada para a matriz
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
