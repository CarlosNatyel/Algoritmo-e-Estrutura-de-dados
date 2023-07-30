#include <stdio.h>

// Enum para representar os meses
typedef enum {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

// Struct Data
typedef struct {
    int dia;
    Mes mes;
    int ano;
} Data;

// Função para obter o nome do mês a partir do enum
const char* getNomeMes(Mes mes) {
    switch (mes) {
        case JANEIRO:
            return "Janeiro";
        case FEVEREIRO:
            return "Fevereiro";
        case MARCO:
            return "Marco";
        case ABRIL:
            return "Abril";
        case MAIO:
            return "Maio";
        case JUNHO:
            return "Junho";
        case JULHO:
            return "Julho";
        case AGOSTO:
            return "Agosto";
        case SETEMBRO:
            return "Setembro";
        case OUTUBRO:
            return "Outubro";
        case NOVEMBRO:
            return "Novembro";
        case DEZEMBRO:
            return "Dezembro";
        default:
            return "Mês Inválido";
    }
}

int main() {
    Data data;

    printf("Digite o dia: ");
    scanf("%d", &data.dia);

    int opcao;
    printf("Digite o mes (1 a 12): ");
    scanf("%d", &opcao);
    data.mes = (Mes)opcao;

    printf("Digite o ano: ");
    scanf("%d", &data.ano);

    // Imprimir a data no formato dd/mm/aaaa
    printf("\nData: %02d/%02d/%04d\n", data.dia, data.mes, data.ano);

    // Imprimir o nome do mês
    printf("Mes: %s\n", getNomeMes(data.mes));

    return 0;
}
