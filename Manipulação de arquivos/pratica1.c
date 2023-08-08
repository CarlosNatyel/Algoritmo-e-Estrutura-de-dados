#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct functionario{
    int id;
    char nome[50];
    float salario;
} Funcionario;

int main() {

    Funcionario funcionario;
    FILE *arquivo;
    char nomearquivo[50];

    printf("Crie o arquivo: ");
    scanf("%s", nomearquivo);

    arquivo = fopen(nomearquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Digite o id do funcionario: ");
    scanf("%d", &funcionario.id);
    
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionario.nome);
    
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    fprintf(arquivo, "%d \n %s \n %f \n", funcionario.id, funcionario.nome, funcionario.salario);

    fclose(arquivo);
    
    return 0;

}
