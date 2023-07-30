#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenar_strings(const char* str1, const char* str2) {
    int tamanho_str1 = strlen(str1);
    int tamanho_str2 = strlen(str2);

    char* resultado = (char*)malloc((tamanho_str1 + tamanho_str2 + 1) * sizeof(char));

    if (resultado == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(resultado, str1);
    strcat(resultado, str2);

    return resultado;
}

int main() {
    char str1[50];
    char str2[50];

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);

    char* resultado = concatenar_strings(str1, str2);

    printf("Resultado da concatenação: %s\n", resultado);

    free(resultado);

    return 0;
}
