#include <stdio.h>

// Enum para representar o gênero da pessoa
typedef enum {
    MASCULINO,
    FEMININO
} Genero;

// Struct Pessoa
typedef struct {
    char nome[100];
    int idade;
    Genero genero;
} Pessoa;

int main() {
    Pessoa pessoa;

    printf("Digite o nome da pessoa: ");
    scanf("%s", pessoa.nome);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);

    int opcao;
    printf("Digite o gênero da pessoa (0 para MASCULINO, 1 para FEMININO): ");
    scanf("%d", &opcao);

    if (opcao == 0) {
        pessoa.genero = MASCULINO;
    } else if (opcao == 1) {
        pessoa.genero = FEMININO;
    } else {
        printf("Opção inválida! Definindo como MASCULINO por padrão.\n");
        pessoa.genero = MASCULINO;
    }

    // Imprimir os dados da pessoa
    printf("\nDados da pessoa:\n");
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Gênero: %s\n", (pessoa.genero == MASCULINO) ? "MASCULINO" : "FEMININO");

    return 0;
}
