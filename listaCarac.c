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


void insereNodoCarac(struct listaCarac *lista, struct nodoCarac *nodo)
{
    if (lista->inicio == NULL)
        lista->inicio = nodo;

    struct nodoCarac *pos = lista->inicio;
    if (nodo->carac < pos->carac) {
        nodo->prox = pos;
        lista->inicio = nodo;
        return;
    }

    while ((pos->prox != NULL) && (pos->prox->carac < nodo->carac))
        pos = pos->prox;
    
    nodo->prox = pos->prox;
    pos->prox = nodo;
    return;
}

void destroiListaCarac(struct listaCarac *lista){
    struct nodoCarac *atras, *pont = lista->inicio;

    while (pont->prox != NULL) {
        destroiListaNum(pont->lista);
        atras = pont;
        pont = pont->prox;
        free(atras);
    }
    destroiListaNum(pont->lista);
    free(pont);
    free(lista);
    return;
}