#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Fruta com os campos nome, cor, sabor e quantidade.
struct Fruta {
    char nome[50];
    char cor[20];
    char sabor[50];
    int quantidade;
};

// Função para cadastrar uma nova fruta no array de frutas.
void cadastrar_fruta(struct Fruta** frutas, int* num_frutas) {
    // Incrementa o número de frutas cadastradas.
    (*num_frutas)++;

    // Realoca memória para o array de frutas com o novo tamanho.
    *frutas = (struct Fruta*)realloc(*frutas, (*num_frutas) * sizeof(struct Fruta));

    // A nova fruta é a última do array, acessamos ela pelo ponteiro nova_fruta.
    struct Fruta* nova_fruta = &((*frutas)[*num_frutas - 1]);

    // Solicita ao usuário informações sobre a nova fruta e as armazena na estrutura.
    printf("Digite o nome da fruta: ");
    scanf("%s", nova_fruta->nome);

    printf("Digite a cor da fruta: ");
    scanf("%s", nova_fruta->cor);

    printf("Digite o sabor da fruta: ");
    scanf("%s", nova_fruta->sabor);

    printf("Digite a quantidade da fruta: ");
    scanf("%d", &nova_fruta->quantidade);
}

// Função para listar todas as frutas cadastradas.
void listar_frutas(const struct Fruta* frutas, int num_frutas) {
    // Verifica se não há frutas cadastradas.
    if (num_frutas == 0) {
        printf("Nenhuma fruta cadastrada ainda.\n");
        return;
    }

    // Imprime as informações de cada fruta no array de frutas.
    printf("Lista de frutas cadastradas:\n");
    for (int i = 0; i < num_frutas; i++) {
        printf("Fruta %d:\n", i + 1);
        printf("Nome: %s\n", frutas[i].nome);
        printf("Cor: %s\n", frutas[i].cor);
        printf("Sabor: %s\n", frutas[i].sabor);
        printf("Quantidade: %d\n", frutas[i].quantidade);
        printf("\n");
    }
}

// Função para buscar frutas pelo nome e imprimir suas informações.
void buscar_fruta_por_nome(const struct Fruta* frutas, int num_frutas, const char* nome) {
    // Variável para contar o número de frutas encontradas com o nome buscado.
    int encontradas = 0;

    // Percorre o array de frutas e verifica se o nome da fruta corresponde ao nome buscado.
    for (int i = 0; i < num_frutas; i++) {
        if (strcmp(frutas[i].nome, nome) == 0) {
            encontradas++;
            printf("Fruta %d:\n", encontradas);
            printf("Nome: %s\n", frutas[i].nome);
            printf("Cor: %s\n", frutas[i].cor);
            printf("Sabor: %s\n", frutas[i].sabor);
            printf("Quantidade: %d\n", frutas[i].quantidade);
            printf("\n");
        }
    }

    // Se não foram encontradas frutas com o nome buscado, imprime uma mensagem.
    if (encontradas == 0) {
        printf("Nenhuma fruta encontrada com o nome '%s'.\n", nome);
    }
}

int main() {
    // Declaração de um ponteiro de Fruta para armazenar o array dinâmico de frutas.
    struct Fruta* frutas = NULL;

    // Variável para armazenar o número de frutas cadastradas.
    int num_frutas = 0;

    // Variável para armazenar o nome de fruta a ser buscada.
    char nome_busca[50];

    int opcao;
    do {
        // Exibe o menu de opções.
        printf("MENU:\n");
        printf("1. Cadastrar nova fruta\n");
        printf("2. Listar todas as frutas cadastradas\n");
        printf("3. Buscar fruta por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executa a opção selecionada pelo usuário.
        switch (opcao) {
            case 1:
                cadastrar_fruta(&frutas, &num_frutas);
                break;
            case 2:
                listar_frutas(frutas, num_frutas);
                break;
            case 3:
                printf("Digite o nome da fruta que deseja buscar: ");
                scanf("%s", nome_busca);
                buscar_fruta_por_nome(frutas, num_frutas, nome_busca);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 4);

    // Libera a memória alocada para o array de frutas antes de sair do programa.
    free(frutas);

    return 0;
}

