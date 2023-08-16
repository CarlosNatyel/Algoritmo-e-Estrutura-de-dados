#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

ContaBancaria* cria_conta(const char titular[], int numero, double saldo) {
    ContaBancaria* conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (conta == NULL) {
        perror("Erro ao alocar memória para conta bancária");
        exit(EXIT_FAILURE);
    }

    strcpy(conta->titular, titular);
    conta->numero = numero;
    conta->saldo = saldo;

    return conta;
}

void deposita(ContaBancaria* conta, double valor) {
    conta->saldo += valor;
}

int saca(ContaBancaria* conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1;  // Saque realizado com sucesso
    } else {
        return 0;  // Saldo insuficiente para saque
    }
}

int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor) {
    if (origem->saldo >= valor) {
        origem->saldo -= valor;
        destino->saldo += valor;
        return 1;  // Transferência realizada com sucesso
    } else {
        return 0;  // Saldo insuficiente para transferência
    }
}

double saldo(ContaBancaria* conta) {
    return conta->saldo;
}

void exclui_conta(ContaBancaria* conta) {
    free(conta);
}
