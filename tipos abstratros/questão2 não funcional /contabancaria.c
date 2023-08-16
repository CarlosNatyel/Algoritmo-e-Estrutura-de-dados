#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

ContaBancaria* cria_conta(const char titular[], int numero, double saldo) {
    ContaBancaria* nova_conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (nova_conta == NULL) {
        perror("Erro ao alocar memória para a conta bancária");
        exit(EXIT_FAILURE);
    }

    strcpy(nova_conta->titular, titular);
    nova_conta->numero = numero;
    nova_conta->saldo = saldo;

    return nova_conta;
}

void deposita(ContaBancaria* conta, double valor) {
    conta->saldo += valor;
}

int saca(ContaBancaria* conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1;  
    } else {
        return 0;  
    }
}

int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor) {
    if (origem->saldo >= valor) {
        origem->saldo -= valor;
        destino->saldo += valor;
        return 1;
    } else {
        return 0;  
    }
}

double saldo(ContaBancaria* conta) {
    return conta->saldo;
}

void exclui_conta(ContaBancaria* conta) {
    free(conta);
}
