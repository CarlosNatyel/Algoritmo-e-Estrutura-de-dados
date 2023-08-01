#include <stdio.h>
#include <math.h>

// Função para calcular a área e o perímetro de um hexágono regular.
void calcula_hexagono(float l, float *area, float *perimetro) {
    // Calcula a área do hexágono usando a fórmula A = (3 * sqrt(3) * l^2) / 2.
    *area = (3 * sqrt(3) * pow(l, 2)) / 2;

    // Calcula o perímetro do hexágono usando a fórmula P = 6 * l.
    *perimetro = 6 * l;
}

int main() {
    // Declaração das variáveis para armazenar o lado, a área e o perímetro do hexágono.
    float lado, area, perimetro;

    // Solicita que o usuário digite o valor do lado do hexágono e armazena na variável lado.
    printf("Digite o valor do lado do hexagono: ");
    scanf("%f", &lado);

    // Chama a função calcula_hexagono para calcular a área e o perímetro do hexágono com base no lado fornecido.
    // Utiliza-se o operador & para passar o endereço das variáveis area e perimetro para a função.
    calcula_hexagono(lado, &area, &perimetro);

    // Imprime o resultado da área e do perímetro do hexágono.
    printf("Area do hexagono: %.2f\n", area);
    printf("Perimetro do hexagono: %.2f\n", perimetro);

    return 0;
}
