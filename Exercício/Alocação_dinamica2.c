#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para concatenar duas strings e retornar uma nova string com o resultado.
char* concatenar_strings(const char* str1, const char* str2) {
    // Obtém o tamanho de ambas as strings.
    int tamanho_str1 = strlen(str1);
    int tamanho_str2 = strlen(str2);

    // Aloca memória para a nova string que irá armazenar o resultado da concatenação.
    // É necessário adicionar 1 ao tamanho total para o caractere nulo '\0'.
    char* resultado = (char*)malloc((tamanho_str1 + tamanho_str2 + 1) * sizeof(char));

    // Verifica se a alocação de memória foi bem-sucedida.
    if (resultado == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    // Copia o conteúdo da primeira string para o resultado.
    strcpy(resultado, str1);

    // Concatena o conteúdo da segunda string ao resultado.
    strcat(resultado, str2);

    // Retorna o ponteiro para a nova string, contendo a concatenação das duas strings de entrada.
    return resultado;
}

int main() {
    // Declara duas variáveis para armazenar as strings digitadas pelo usuário.
    char str1[50];
    char str2[50];

    // Solicita que o usuário digite a primeira string e a armazena na variável str1.
    printf("Digite a primeira string: ");
    scanf("%s", str1);

    // Solicita que o usuário digite a segunda string e a armazena na variável str2.
    printf("Digite a segunda string: ");
    scanf("%s", str2);

    // Chama a função para concatenar as duas strings e armazena o resultado em uma variável.
    char* resultado = concatenar_strings(str1, str2);

    // Imprime o resultado da concatenação.
    printf("Resultado da concatenação: %s\n", resultado);

    // Libera a memória alocada para a string resultado para evitar vazamentos de memória.
    free(resultado);

    return 0;
}

