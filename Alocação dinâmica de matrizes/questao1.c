//Pratica Vetores e matrizes 
//Questão 1:

int main(void) {
    int tamanho, i;
    int *vetor;

    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Aloca dinamicamente um vetor de tamanho especificado pelo usuário
    vetor = (int *)malloc(tamanho * sizeof(int));

    // Solicita ao usuário que digite os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Imprime os elementos do vetor em ordem inversa
    printf("\nElementos do vetor em ordem inversa:\n");
    for (i = tamanho - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada para o vetor antes de encerrar o programa
    free(vetor);

    return 0;
}

