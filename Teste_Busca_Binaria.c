


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
