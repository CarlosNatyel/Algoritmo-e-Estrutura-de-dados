//Questão 1:
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

