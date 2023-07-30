#include <stdio.h>
#include <stdlib.h>

int* somar_vetores(const int* vetor1, const int* vetor2, int tamanho) {
    int* resultado = (int*)malloc(tamanho * sizeof(int));
    int i;

    for (i = 0; i < tamanho; i++) {
        resultado[i] = vetor1[i] + vetor2[i];
    }

    return resultado;
}

int main() {
    int vetor1[] = {1, 2, 3, 4};
    int vetor2[] = {5, 6, 7, 8};
    int tamanho = sizeof(vetor1) / sizeof(vetor1[0]);

    int* resultado = somar_vetores(vetor1, vetor2, tamanho);

    printf("Resultado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    
    free(resultado);

    return 0;
}
