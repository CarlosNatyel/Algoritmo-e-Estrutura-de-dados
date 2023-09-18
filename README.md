gcc -c conta.c

gcc -c main.c

gcc -o main conta.o main.o

//criar a pasta

desisto de linguagem c vo aprender python

#include <stdio.h>
#include <stdlib.h>

#define N 50

// Definição da estrutura da pilha
struct Pilha {
    int n;
    float vet[N];
};

typedef struct Pilha Pilha; // Alias para struct Pilha

// Função para criar uma pilha vazia
Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha* p) {
    return (p->n == 0);
}

// Função para empilhar um valor na pilha
void pilha_push(Pilha* p, float v) {
    if (p->n == N) {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

// Função para desempilhar um valor da pilha
float pilha_pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    float v = p->vet[p->n - 1];
    p->n--;
    return v;
}

// Função para liberar a memória da pilha
void pilha_libera(Pilha* p) {
    free(p);
}

int main() {
    Pilha* minhaPilha = pilha_cria();

    // Testando a pilha
    pilha_push(minhaPilha, 10.5);
    pilha_push(minhaPilha, 20.3);

    while (!pilha_vazia(minhaPilha)) {
        float valor = pilha_pop(minhaPilha);
        printf("Valor desempilhado: %.2f\n", valor);
    }

    pilha_libera(minhaPilha);

    return 0;
}
