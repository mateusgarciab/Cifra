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


void insereNodoCarac(struct listaCarac *lista, char letra, int num)
{
    if ((lista->inicio == NULL) || (lista->inicio->carac < letra)) {
        struct nodoCarac *inn = lista->inicio;
        lista->inicio = alocaNodoCarac();
        lista->inicio->prox = inn;
        lista->inicio->carac = letra;
        insereNodoNum(lista->inicio->lista, num);

        return;
    }

    struct nodoCarac *pos = lista->inicio;
    
    while ((pos->prox != NULL) && (pos->prox->carac < letra))
        pos = pos->prox;
    
    if (pos->carac == letra) {
        insereNodoNum(pos->lista, num);
        return;
    }

    if (pos->prox->carac == letra) { //se eu to no certo e ele existe
        insereNodoNum(pos->prox->lista, num);
        return;
    } 

    struct nodoCarac *novo = alocaNodoCarac();
    novo->carac = letra;
    insereNodoNum(novo->lista, num);
    novo->prox = pos->prox;
    pos->prox = novo;

    return;
}

void destroiListaCarac(struct listaCarac *lista){
    struct nodoCarac *atras, *pont = lista->inicio;

    if (lista->inicio == NULL) {
        free(lista);
        return;
    }


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