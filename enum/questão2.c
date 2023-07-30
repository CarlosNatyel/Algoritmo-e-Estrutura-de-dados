#include <stdio.h>

// Enum para representar os tipos do produto
typedef enum {
    ALIMENTO,
    BEBIDA,
    ELETRONICO
} TipoProduto;

// Union para armazenar um dos tipos do produto
typedef union {
    char alimento[50];
    char bebida[50];
    char eletronico[50];
} Tipo;

// Struct Produto
typedef struct {
    char nome[100];
    float preco;
    TipoProduto tipo;
    Tipo tipoDetalhado;
} Produto;

int main() {
    Produto produto;

    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);

    int opcao;
    printf("Digite o tipo do produto (0 para ALIMENTO, 1 para BEBIDA, 2 para ELETRONICO): ");
    scanf("%d", &opcao);

    if (opcao == 0) {
        produto.tipo = ALIMENTO;
        printf("Digite o tipo de alimento: ");
        scanf("%s", produto.tipoDetalhado.alimento);
    } else if (opcao == 1) {
        produto.tipo = BEBIDA;
        printf("Digite o tipo de bebida: ");
        scanf("%s", produto.tipoDetalhado.bebida);
    } else if (opcao == 2) {
        produto.tipo = ELETRONICO;
        printf("Digite o tipo de eletrônico: ");
        scanf("%s", produto.tipoDetalhado.eletronico);
    } else {
        printf("Opção inválida! Definindo como ALIMENTO por padrão.\n");
        produto.tipo = ALIMENTO;
        printf("Digite o tipo de alimento: ");
        scanf("%s", produto.tipoDetalhado.alimento);
    }

    // Imprimir os dados do produto
    printf("\nDados do produto:\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preço: %.2f\n", produto.preco);
    printf("Tipo: ");
    switch (produto.tipo) {
        case ALIMENTO:
            printf("%s\n", produto.tipoDetalhado.alimento);
            break;
        case BEBIDA:
            printf("%s\n", produto.tipoDetalhado.bebida);
            break;
        case ELETRONICO:
            printf("%s\n", produto.tipoDetalhado.eletronico);
            break;
    }

    return 0;
}
