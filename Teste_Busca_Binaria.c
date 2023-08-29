
Fix Binary Search Algorithm

Default (GPT-3.5)

User
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"

struct funcionario
{
    char nome[21], cargo[21], documento[21];
};

void resgitra_funcionario(Funcionario *funcionario, FILE *arquivo)
{
    funcionario = (Funcionario *) malloc(sizeof(Funcionario));

    arquivo = fopen("funcionario.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    
    printf("Informe o nome:");
    scanf(" %[^\n]", funcionario->nome);
    printf("Informe o cargo:");
    scanf(" %[^\n]", funcionario->cargo);
    printf("Informe o documento:");
    scanf(" %[^\n]", funcionario->documento);

    fprintf(arquivo, "%s\n%s\n%s", funcionario->nome, funcionario->cargo, funcionario->documento);

    fclose(arquivo);
    free(funcionario);
}

int quantifica_funcionarios(FILE *arquivo)
{
    int nlinhas = 0, c;
    arquivo = fopen("funcionario.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            nlinhas++;
        }
    }
    return nlinhas/3;
}

Funcionario *carrega_dados(Funcionario *funcionarios, FILE *arquivo, int nfuncionarios)
{
    int i;
    funcionarios = (Funcionario *) malloc(nfuncionarios * sizeof(Funcionario));
    if (funcionarios == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    
    arquivo = fopen("funcionario.txt", "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    for (i = 0; i < nfuncionarios; i++) {
        fscanf(arquivo, "%s", funcionarios[i].nome);
        fscanf(arquivo, "%s", funcionarios[i].cargo);
        fscanf(arquivo, "%s", funcionarios[i].documento);
    }

    fclose(arquivo);
    return funcionarios;
}

void libera_funcionarios(Funcionario *funcionarios)
{
    free(funcionarios);
}

int buscaBinaria(Funcionario *funcionarios, int tamanho)
{
    char chave[21];
    printf("Informe o Nome ou Documento: ");
    scanf(" %[^\n]", chave);
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (funcionarios[meio].nome == chave || funcionarios[meio].documento == chave) {
            return meio;
        } else if (funcionarios[meio].nome < chave || funcionarios[meio].documento < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
} conserte o algoritmo  de busca binária 


ChatGPT
It looks like you're sharing C code for a program that manages employee data. You're also asking for help to fix the binary search algorithm. I've noticed a couple of issues in your code snippet:

Memory Allocation: In the resgitra_funcionario function, you are allocating memory for the funcionario pointer, but then you overwrite it with the malloc result. You should modify the function argument directly.

String Comparison: In the buscaBinaria function, you're using the wrong comparison operator (<, >) to compare strings. You should use strcmp function for string comparison.

Here's the corrected version of the buscaBinaria function:

c
Copy code
int buscaBinaria(Funcionario *funcionarios, int tamanho)
{
    char chave[21];
    printf("Informe o Nome ou Documento: ");
    scanf(" %[^\n]", chave);
    
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        int cmp = strcmp(funcionarios[meio].nome, chave);
        
        if (cmp == 0) {
            return meio;  // Found a match
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    return -1;  // Not found
