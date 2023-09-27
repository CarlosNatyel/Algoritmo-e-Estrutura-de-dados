gcc -c conta.c

gcc -c main.c

gcc -o main conta.o main.o

//criar a pasta

desisto de linguagem c vo aprender python

int contaFuncionarios(Funcionario *ponteiroLista) {
    int contador = 0;
    Funcionario *atual = ponteiroLista;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int quantidadeDeFuncionarios = contaFuncionarios(ponteiroParaLista);
printf("Total de funcionários na lista: %d\n", quantidadeDeFuncionarios);

