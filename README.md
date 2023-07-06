Questão 1:
#include <stdio.h>

int main(void) {
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("Valor de x = %d\n", x);
    printf("Valor de y = %d\n", y);
    printf("Valor de p = %p\n", *p);

    return 0;
}
x=3
y=4
p=4



Questão 2:

a) Sim, o compilador nos fornecerá uma mensagem de erro.

b) O compilador emite essa mensagem de erro porque há um problema de incompatibilidade de tipo. A linha p = x; tenta atribuir um valor inteiro (x) a um ponteiro (p), o que não é permitido. O compilador espera que o lado direito da atribuição seja um endereço de memória, não um valor inteiro.

c) Se você tentar compilar e executar o programa original, a compilação falhará devido ao erro mencionado acima. Portanto, a execução não será bem-sucedida.

d) Para evitar que o compilador emita uma mensagem de erro, você precisa corrigir o código. Em vez de atribuir x diretamente a p, você precisa atribuir o endereço de x usando o operador de endereço &. Aqui está o trecho de código modificado:

p = &x;
e) Após modificar o código conforme indicado, se você compilar e executar o programa, a execução será bem-sucedida. A mensagem de erro não será mais emitida, e o programa imprimirá o valor de p (o endereço de x) e o valor de *p (o valor armazenado em x).

#include <stdio.h>

int main(void) {                                            
    int x, *p;
    x = 100;
    p = &x;  
    printf("Valor de p = %p\tValor de *p = %d", (void *)p, *p); 
    return 0;
}
