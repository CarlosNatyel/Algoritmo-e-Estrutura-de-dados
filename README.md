gcc -c conta.c

gcc -c main.c

gcc -o main conta.o main.o

//criar a pasta

desisto de linguagem c vo aprender python

void imprimeFuncionarios(Funcionario *ponteiroLista) {
    Funcionario *atual = ponteiroLista;

    printf("Lista de Funcionários:\n");
    
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("CPF: %s\n", atual->cpf);
        printf("Cargo: %s\n", atual->cargo);
        printf("Setor: %s\n", atual->setor);
        printf("Salário: %.2f\n", atual->salario);
        printf("Data de Contratação: %s\n", atual->dataContratacao);
        printf("Jornada de Trabalho: %s\n", atual->jornadaTrabalho);
        printf("\n"); // Uma linha em branco para separar os funcionários
        
        atual = atual->proximo; // Avança para o próximo funcionário na lista
    }
}



