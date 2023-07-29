#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[60];
    float salario;
    int identificador;
    char cargo[60];
} Funcionario;

void preencher(Funcionario* funcionarios, int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        printf("Informe o nome do funcionario: ");
        scanf(" %[^\n]s", funcionarios[i].nome);
        printf("Informe o salario: ");
        scanf("%f", &funcionarios[i].salario);
        printf("Informe o identificador do funcionario: ");
        scanf("%d", &funcionarios[i].identificador);
        printf("Informe o cargo: ");
        scanf(" %[^\n]s", funcionarios[i].cargo);

        printf("Nome do funcionario: %s, salario: %.1f, identificador: %d, cargo: %s\n",
               funcionarios[i].nome, funcionarios[i].salario, funcionarios[i].identificador, funcionarios[i].cargo);
    }
}

float aumentaSalario(Funcionario* funcionarios, int indice) {
    funcionarios[indice].salario += 1000;
    return funcionarios[indice].salario;
}

void maiorMenorSalario(Funcionario* funcionarios, int qtd) {
    float menor = 0, maior = 0;
    int indice_maior, indice_menor;
    int i;
    for (i = 0; i < qtd; i++) {
        if (i == 0) {
            menor = funcionarios[i].salario;
        }
        if (funcionarios[i].salario > maior) {
            maior = funcionarios[i].salario;
            indice_maior = i;
        }
        if (funcionarios[i].salario < menor) {
            menor = funcionarios[i].salario;
            indice_menor = i;
        }
    }
    printf("O funcionario com maior salario e %s, com salario de %.1f\n", funcionarios[indice_maior].nome, funcionarios[indice_maior].salario);
    printf("O funcionario com menor salario e %s, com salario de %.1f\n", funcionarios[indice_menor].nome, funcionarios[indice_menor].salario);
}

int main() {
    int quantidade;
    printf("Informe a quantidade de funcionarios: ");
    scanf("%i", &quantidade);

    Funcionario* funcionarios = (Funcionario*)malloc(quantidade * sizeof(Funcionario));
    if (funcionarios == NULL) {
        exit(1);
    }

    preencher(funcionarios, quantidade);
    aumentaSalario(funcionarios, 0);
    maiorMenorSalario(funcionarios, quantidade);

    free(funcionarios);
    return 0;
}
