#include <stdio.h>
#include <stdlib.h>

// Função para somar dois vetores elemento por elemento e retornar um novo vetor com o resultado.
int* somar_vetores(const int* vetor1, const int* vetor2, int tamanho) {
    // Aloca memória para o vetor resultado.
    int* resultado = (int*)malloc(tamanho * sizeof(int));
    int i;

    // Percorre cada elemento dos vetores e os soma.
    for (i = 0; i < tamanho; i++) {
        resultado[i] = vetor1[i] + vetor2[i];
    }

    // Retorna o ponteiro para o vetor resultado.
    return resultado;
}

int main() {
    // Declara dois vetores.
    int vetor1[] = {1, 2, 3, 4};
    int vetor2[] = {5, 6, 7, 8};

    // Calcula o tamanho dos vetores.
    int tamanho = sizeof(vetor1) / sizeof(vetor1[0]);

    // Chama a função para somar os dois vetores e armazena o resultado em um novo vetor.
    int* resultado = somar_vetores(vetor1, vetor2, tamanho);

    // Imprime o vetor resultado.
    printf("Resultado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    // Libera a memória alocada para o vetor resultado para evitar vazamentos de memória.
    free(resultado);

    return 0;
}

