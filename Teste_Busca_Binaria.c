
// Declaração dos protótipos das novas funções
void lerNomesDocumentosOrdenados(char ***nomes, char ***documentos, int *nfuncionarios);
int buscaBinaria(char **dados, int n, const char *alvo);

// Função para ler os nomes e documentos do arquivo e retornar em vetores ordenados
void lerNomesDocumentosOrdenados(char ***nomes, char ***documentos, int *nfuncionarios)
{
    FILE *arquivo = fopen("funcionario.txt", "rt");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int nlinhas = quantifica_funcionarios(arquivo);
    *nfuncionarios = nlinhas;

    *nomes = (char **)malloc(nlinhas * sizeof(char *));
    *documentos = (char **)malloc(nlinhas * sizeof(char *));
    if (*nomes == NULL || *documentos == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    for (int i = 0; i < nlinhas; i++)
    {
        (*nomes)[i] = (char *)malloc(21 * sizeof(char));
        (*documentos)[i] = (char *)malloc(21 * sizeof(char));
        if ((*nomes)[i] == NULL || (*documentos)[i] == NULL)
        {
            printf("Erro ao alocar memória\n");
            exit(1);
        }

        fscanf(arquivo, " %[^\n]", (*nomes)[i]);
        fscanf(arquivo, " %[^\n]", (*documentos)[i]);
        // Ignorar a linha de cargo
        fscanf(arquivo, "%*[^\n]");
    }

    fclose(arquivo);

    // Ordenar nomes usando qsort
    qsort(*nomes, nlinhas, sizeof(char *), compararStrings);
    // Ordenar documentos usando qsort
    qsort(*documentos, nlinhas, sizeof(char *), compararStrings);
}

// Função de busca binária
int buscaBinaria(char **dados, int n, const char *alvo)
{
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(dados[meio], alvo);

        if (cmp == 0)
        {
            return meio; // Encontrado
        }
        else if (cmp < 0)
        {
            esquerda = meio + 1; // Procurar na metade direita
        }
        else
        {
            direita = meio - 1; // Procurar na metade esquerda
        }
    }

    return -1; // Não encontrado
}

// ...

int main()
{
    // ...

    char **nomes;
    char **documentos;
    int nfuncionarios;

    lerNomesDocumentosOrdenados(&nomes, &documentos, &nfuncionarios);

    // ... Utilize os vetores "nomes" e "documentos" conforme necessário ...

    for (int i = 0; i < nfuncionarios; i++)
    {
        free(nomes[i]);
        free(documentos[i]);
    }
    free(nomes);
    free(documentos);
