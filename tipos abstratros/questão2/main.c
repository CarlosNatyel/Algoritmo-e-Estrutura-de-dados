#include <stdio.h>
#include "contabancaria.h"

int main() {
    ContaBancaria* conta1 = cria_conta("João", 1001, 1500.0);
    ContaBancaria* conta2 = cria_conta("Maria", 1002, 2000.0);

    deposita(conta1, 500.0);
    saca(conta2, 300.0);
    transfere(conta1, conta2, 200.0);

    printf("Saldo da Conta 1: %.2f\n", saldo(conta1));
    printf("Saldo da Conta 2: %.2f\n", saldo(conta2));

    exclui_conta(conta1);
    exclui_conta(conta2);

    return 0;
}
