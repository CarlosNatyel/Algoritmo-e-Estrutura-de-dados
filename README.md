gcc -c conta.c

gcc -c main.c

gcc -o main conta.o main.o

//criar a pasta

desisto de linguagem c vo aprender python

#define N 50

struct pilha

{
    int n;
    float vet[N];
};
Pilha*pilha_cria(void){
    Pilha*p=(Pilha*) malloc(sizeof(Pilha));
    p->n=0
    return p;
}
void pilha_push(Pilha*p,float v){
    if(p->n==N){
        printf("Capacidade da pilha estourou. \n")
        exit(1);
    }
    p->vet[p->n]=v;
    p->n++;

    int pilha_vazia(Pilha*p){
        return (p->n==0);
    }
    float pilha_pop(Pilha*p){
        float v;
        if(pilha_vazia(p)){
            printf("Pilha vazia.\n")
            exit(1);

        }
        v=p->vet[p->n-1];
        p->n--;
        return v;
    }
    void pilha_libera(Pilha*p){
        free(p);
    }
}
int main() {
    Pilha* minhaPilha = pilha_cria();

    // Testando a pilha
    printf("Empilhando valores...\n");
    pilha_push(minhaPilha, 10.5);
    pilha_push(minhaPilha, 20.3);
    pilha_push(minhaPilha, 5.0);

    printf("Desempilhando valores...\n");
    while (!pilha_vazia(minhaPilha)) {
        float valor = pilha_pop(minhaPilha);
        printf("Valor desempilhado: %.2f\n", valor);
    }

    pilha_libera(minhaPilha);

    return 0;
}

