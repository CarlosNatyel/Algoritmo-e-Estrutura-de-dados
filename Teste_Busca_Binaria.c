

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    return strcmp(((Funcionario *)a)->nome, ((Funcionario *)b)->nome);
}

// Função para ler somente os nomes e documentos do arquivo e retornar ordenado
Funcionario *ler_nomes_documentos_ordenados(FILE *arquivo, int nfuncionarios) {
    Funcionario *funcionarios = (Funcionario *) malloc(nfuncionarios * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória");
        exit(1);
    }

    arquivo = fopen("funcionario.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 0; i < nfuncionarios; i++) {
        fscanf(arquivo, "%s", funcionarios[i].nome);
        fscanf(arquivo, "%s", funcionarios[i].cargo);
        fscanf(arquivo, "%s", funcionarios[i].documento);
    }

    fclose(arquivo);

    // Ordena os funcionários pelo nome usando qsort
    qsort(funcionarios, nfuncionarios, sizeof(Funcionario), compare);

    return funcionarios;
}

// Função de busca binária para encontrar um funcionário pelo nome
int busca_binaria(Funcionario *funcionarios, int nfuncionarios, const char *nome) {
    int esquerda = 0, direita = nfuncionarios - 1;
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        int comparacao = strcmp(funcionarios[meio].nome, nome);
        
        if (comparacao == 0) {
            return meio; // Funcionário encontrado
        }
        else if (comparacao < 0) {
            esquerda = meio + 1; // Procura na metade direita
        }
        else {
            direita = meio - 1; // Procura na metade esquerda
        }
    }

    return -1; // Funcionário não encontrado
}
