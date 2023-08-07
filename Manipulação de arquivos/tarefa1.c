#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char funcional[10];
    char nome[50];
    char departamento;
    float salario;
} Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal) {
    *pessoal = (Funcionario*)malloc(n * sizeof(Funcionario));
    for (int i = 0; i < n; i++) {
        fscanf(fl, "%s %s %c %f", (*pessoal)[i].funcional, (*pessoal)[i].nome, &(*pessoal)[i].departamento, &(*pessoal)[i].salario);
    }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto) {
    float totalGasto = 0.0;
    printf("Funcionarios do departamento %c:\n", depto);
    for (int i = 0; i < n; i++) {
        if ((*pessoal)[i].departamento == depto) {
            totalGasto += (*pessoal)[i].salario;
            printf("Funcional: %s | Nome: %s | Salario: %.2f\n", (*pessoal)[i].funcional, (*pessoal)[i].nome, (*pessoal)[i].salario);
        }
    }
    printf("Total gasto com o departamento %c: %.2f\n", depto, totalGasto);
}

int main() {
    FILE* arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int num_func;
    fscanf(arquivo, "%d", &num_func);

    Funcionario* pessoal;
    copia_dados(arquivo, num_func, &pessoal);

    fclose(arquivo);

    imprime_folha_pagamento(num_func, &pessoal, 'A');
    imprime_folha_pagamento(num_func, &pessoal, 'B');
    imprime_folha_pagamento(num_func, &pessoal, 'C');

    free(pessoal);

    return 0;
}
