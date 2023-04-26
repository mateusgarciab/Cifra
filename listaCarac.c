#include <stdio.h>
#include <stdlib.h>

#include "listaCarac.h"
#include "posicoes.h"

struct listaCarac *iniciaLiastaCarac()
{
    struct listaCarac *lista = malloc(sizeof(struct listaCarac));
    if (!lista)
        return NULL;

    lista->inicio = NULL;
    return lista;
}
 
struct nodoCarac *alocaNodoCarac()
{
    struct nodoCarac *novo = malloc(sizeof(struct nodoCarac));
    if (!novo)
        return NULL;

    novo->lista = inicializaLista();
    novo->prox = NULL;

    return novo;
}

void insereLista(struct listaCarac *lista, int valor){
    insereNodoNum(lista->inicio->lista, valor);
    return;
}

void insereNodoCarac(struct listaCarac *lista, struct nodoCarac *nodo)
{
    if (lista->inicio == NULL)
        lista->inicio = nodo;
        
    struct nodoCarac *pos = lista->inicio;
    while ((pos->prox != NULL) && (pos->carac < nodo->carac))
        pos = pos->prox;
    
    
}