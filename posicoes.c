#include <stdio.h>
#include <stdlib.h>

#include "posicoes.h"

struct listaNum *inicializaLista()
{
    struct listaNum *lista = malloc(sizeof(struct listaNum));
    if (!lista)
        return NULL;

    lista->inicio = NULL;
    lista->tam = 0;

    return lista;
}

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

void destroiListaNum(struct listaNum *lista)
{
    struct nodoNum *nodo, *prox;
    nodo = lista->inicio;
    while (nodo->prox != NULL) {
        prox = nodo->prox;
        desalocaNodoNum(nodo);
        nodo = prox;
    }
    
    desalocaNodoNum(nodo);
    free(lista);
    
    return;
}

void insereNodoNum(struct listaNum *lista, int valor)
{
    struct nodoNum *nodo = alocaNodoNum();
    nodo->valor = valor;
    nodo->prox = lista->inicio;
    lista->inicio = nodo;
    lista->tam++;

    printf("%d\n", lista->inicio->valor);

    return;
}

void imprimeListaNum(struct listaNum *lista)
{
    if (lista->tam == 0)
        return;

    struct nodoNum *nodo = lista->inicio;
    while (nodo->prox != NULL) {
        printf("%d\n", nodo->valor);
        nodo = nodo->prox;
    }
    printf("%d\n", nodo->valor);
    
    return;
}

int aleatNum(struct listaNum *lista)
{
    int num;
    num = rand() % (lista->tam);

    struct nodoNum *nodo = lista->inicio;
    while (num > 0) {
        nodo = nodo->prox;
        num--;
    }

    return nodo->valor;
}