include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
#include "circulo.h"

int main(void){

 
    Ponto* p = cria(2.0,1.0);
    Circulo* C = circ_cria(4, 4, 2);
    float a = circ_area(C);
    printf("A area do circulo es: %.1f\n", a);
    circ_interior(p, C)?printf("Ponto no circulo \n"):printf("Ponto nao esta circulo \n");

    circ_libera(C);

    return 0;
}
