//Apenas o programa de busca binaria(tentativa)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"



int busca_binaria_nome(Funcionario *funcionarios, int quant_funcionarios,  char *alvo) {
    
}

int busca_binaria_documento(Funcionario *funcionarios, int quant_funcionarios, char *alvo) {
    
}

int main() {
    

    int opcao;
    printf("1 - Buscar por nome\n");
    printf("2 - Buscar por documento\n");
    printf("Escolha a opcao:");
    scanf("%d", &opcao);

    if (opcao == 1) {
        char nome_alvo[21];
        printf("Informe o nome para busca: ");
        scanf(" %[^\n]", nome_alvo);
        
        int posicao = busca_binaria_nome(funcionarios, quant_funcionarios, nome_alvo);
        if (posicao != -1) {
            printf("Funcionário encontrado:\n%s\n%s\n%s\n", funcionarios[posicao].nome,
                   funcionarios[posicao].cargo, funcionarios[posicao].documento);
        } else {
            printf("Funcionário não encontrado.\n");
        }
    } else if (opcao == 2) {
        char doc_alvo[21];
        printf("Informe o documento para busca: ");
        scanf(" %[^\n]", doc_alvo);
        
        int posicao = busca_binaria_documento(funcionarios, quant_funcionarios, doc_alvo);
        if (posicao != -1) {
            printf("Funcionário encontrado:\n%s\n%s\n%s\n", funcionarios[posicao].nome,
                   funcionarios[posicao].cargo, funcionarios[posicao].documento);
        } else {
            printf("Funcionário não encontrado.\n");
        }
    } else {
        printf("Opção inválida.\n");
    }

    
    
    return 0;
}
