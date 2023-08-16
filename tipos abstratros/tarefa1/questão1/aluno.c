#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* aluno_cria(char* nome, float nota) {
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    if (novo_aluno != NULL) {
        novo_aluno->nome = strdup(nome); 
        novo_aluno->nota = nota;
    }
    return novo_aluno;
}

void aluno_libera(Aluno* a) {
    if (a != NULL) {
        free(a->nome); 
        free(a);
    }
}

void aluno_imprime(Aluno* a) {
    if (a != NULL) {
        printf("Nome: %s\nNota: %.2f\n", a->nome, a->nota);
    }
}

int compare_alunos(const void* a, const void* b) {
    Aluno* aluno_a = *(Aluno**)a;
    Aluno* aluno_b = *(Aluno**)b;
    return strcmp(aluno_a->nome, aluno_b->nome);
}

void aluno_ordena(int n, Aluno** v) {
    qsort(v, n, sizeof(Aluno*), compare_alunos);
}

void aluno_salva(FILE* fp, int n, Aluno** v) {
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s\t%.2f\n", v[i]->nome, v[i]->nota);
    }
}
