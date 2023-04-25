#include <stdio.h>
#include <stdlib.h>

#include "posicoes.h"

struct nodoNum *alocaNodoNum()
{
    struct nodoNum *novo = malloc(sizeof(struct nodoNum));
    if (!novo)
        return NULL;

    novo->prox = NULL;
    return novo;
}

void desalocaNodoNum(struct nodoNum *nodo)
{
    free(nodo);
    return;
}

void destroilistaNum(struct nodoNum *raiz)
{
    struct nodoNum *nodo, *prox;
    nodo = raiz;
    while (nodo->prox != NULL) {
        prox = nodo->prox;
        desalocaNodoNum(nodo);
        nodo = prox;
    }
    desalocaNodoNum(nodo);
    
    return;
}

void insereNodoNum(struct nodoNum *raiz, int valor)
{
    struct nodoNum *nodo = alocaNodoNum();
    nodo->valor = valor;
    nodo->prox = raiz;
    raiz = nodo;

    printf("%d\n", nodo->valor);

    return;
}

void imprimeListaNum(struct nodoNum *raiz)
{
    if (raiz == NULL)
        return;

    struct nodoNum *nodo = raiz;
    while (nodo->prox != NULL) {
        printf("%d\n", nodo->valor);
        nodo = nodo->prox;
    }
    
    return;
}