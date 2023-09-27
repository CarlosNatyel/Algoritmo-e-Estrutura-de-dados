gcc -c conta.c

gcc -c main.c

gcc -o main conta.o main.o

//criar a pasta

desisto de linguagem c vo aprender python

Funcionario *buscaFuncionario(Funcionario *ponteiroLista, char *nome) {
    Funcionario *atual = ponteiroLista;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            // Employee with the given name found
            return atual;
        }

        atual = atual->proximo;
    }

    // Employee with the given name not found
    return NULL;
}


