#include "aluno.h"

int main() {
    Aluno* alunos[5];
    //teste de alunos
    alunos[0] = aluno_cria("Dante", 8.5);
    alunos[1] = aluno_cria("Emanuel", 7.2);
    alunos[2] = aluno_cria("Gustavo", 9.0);
    alunos[3] = aluno_cria("Natyel", 5.3);
    alunos[4] = aluno_cria("Pedro", 9.5);
     //emprimir os dados do alunos
    printf("Dados dos alunos:\n");
    for (int i = 0; i < 5; i++) {
        aluno_imprime(alunos[i]);
        printf("\n");
    }

    aluno_ordena(5, alunos);
    //salva os alunos em um arquivo de texto
    FILE* fp = fopen("alunos.txt", "w");
    if (fp != NULL) {
        aluno_salva(fp, 5, alunos);
        fclose(fp);
    }
    //libera um espaço na memoria pros alunos
    for (int i = 0; i < 5; i++) {
        aluno_libera(alunos[i]);
    }

    return 0;
}
