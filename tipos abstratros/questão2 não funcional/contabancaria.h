#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
// verificando se o símbolo CONTABANCARIA_H já foi definido. 
typedef struct {
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
