#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fruta {
    char nome[50];
    char cor[20];
    char sabor[50];
    int quantidade;
};

void cadastrar_fruta(struct Fruta** frutas, int* num_frutas) {
    (*num_frutas)++;
    *frutas = (struct Fruta*)realloc(*frutas, (*num_frutas) * sizeof(struct Fruta));
    struct Fruta* nova_fruta = &((*frutas)[*num_frutas - 1]);

    printf("Digite o nome da fruta: ");
    scanf("%s", nova_fruta->nome);

    printf("Digite a cor da fruta: ");
    scanf("%s", nova_fruta->cor);

    printf("Digite o sabor da fruta: ");
    scanf("%s", nova_fruta->sabor);

    printf("Digite a quantidade da fruta: ");
    scanf("%d", &nova_fruta->quantidade);
}

void listar_frutas(const struct Fruta* frutas, int num_frutas) {
    if (num_frutas == 0) {
        printf("Nenhuma fruta cadastrada ainda.\n");
        return;
    }

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

void buscar_fruta_por_nome(const struct Fruta* frutas, int num_frutas, const char* nome) {
    int encontradas = 0;

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

    if (encontradas == 0) {
        printf("Nenhuma fruta encontrada com o nome '%s'.\n", nome);
    }
}

int main() {
    struct Fruta* frutas = NULL;
    int num_frutas = 0;
    char nome_busca[50];

    int opcao;
    do {
        printf("MENU:\n");
        printf("1. Cadastrar nova fruta\n");
        printf("2. Listar todas as frutas cadastradas\n");
        printf("3. Buscar fruta por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

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

    free(frutas);

    return 0;
}
