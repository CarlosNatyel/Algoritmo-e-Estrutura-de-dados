gcc -c conta.c

gcc -c main.c

gcc -o main conta.o main.o

//criar a pasta

desisto de linguagem c vo aprender python

#include <stdio.h>
#include <stdlib.h>

struct retangulo
{
    float b;
    float h;
};

typedef struct retangulo Retangulo;

struct lista{
	Retangulo info;
	struct lista*prox;
};

static Lista *aloca(float b,float h){
	Lista*p=(Lista*) malloc(sizeof(Lista));
	p->info.b=b
	p->info.h=h
	p->prox=NULL;
	return p;
}




Lista2 *lst2_busca(Lista2 *l, int v)
{
    Lista2 *p;

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == v)
            return p;
    }
    return NULL;
}

Lista2 *lst2_retira(Lista2 *l, int v)
{
    if (l == NULL)
    {
        return NULL; 
    }

    Lista2 *p = lst2_busca(l, v);

    if (p == NULL)
    {
        return l; 
    }

    if (l == p)
    {
        l = p->prox;
    }
    else
    {
        p->ant->prox = p->prox;
    }

    if (p->prox != NULL)
    {
        p->prox->ant = p->ant;
    }

    free(p);

    return l;
}

int main()
{
    
    Lista2 *minhaLista = NULL;

    minhaLista = lst2_insere(minhaLista, 1);
    minhaLista = lst2_insere(minhaLista, 2);
    minhaLista = lst2_insere(minhaLista, 3);

    printf("Lista: ");
    Lista2 *p;
    for (p = minhaLista; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
    printf("\n");

    minhaLista = lst2_retira(minhaLista, 2);

    printf("Lista após a remoção: ");
    for (p = minhaLista; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
    printf("\n");

    return 0;
}


