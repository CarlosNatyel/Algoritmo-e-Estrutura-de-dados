#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct ContaBancaria {
    char titular[100];
    int numero;
    double saldo;
} ContaBancaria;

ContaBancaria* cria_conta(const char titular[], int numero, double saldo);
void deposita(ContaBancaria* conta, double valor);
int saca(ContaBancaria* conta, double valor);
int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor);
double saldo(ContaBancaria* conta);
void exclui_conta(ContaBancaria* conta);

#endif
