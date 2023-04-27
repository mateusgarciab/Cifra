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
    if ((lista->inicio == NULL) || (letra < lista->inicio->carac)) {
        struct nodoCarac *inn = lista->inicio;
        lista->inicio = alocaNodoCarac();
        lista->inicio->prox = inn;
        lista->inicio->carac = letra;
        insereNodoNum(lista->inicio->lista, num);

        return;
    }

    struct nodoCarac *pos = lista->inicio;
    
    while ((pos->prox != NULL) && (letra > pos->prox->carac))
        pos = pos->prox;
    
    if (pos->carac == letra) {
        insereNodoNum(pos->lista, num);
        return;
    }

    /* cria e coloca no final da lista caso o local dessa letra seja no final 
        e tambem cria caso ele nao exista mas existem outros depois */
    if ((pos->prox == NULL) || ((pos->prox != NULL) && (pos->prox->carac != letra))) { //se eu to no certo e ele existe
        struct nodoCarac *novo = alocaNodoCarac();
        novo->carac = letra;
        insereNodoNum(novo->lista, num);
        novo->prox = pos->prox;
        pos->prox = novo;
    } else {
        insereNodoNum(pos->prox->lista, num);
    }

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

void imprimeLista(struct listaCarac *lista)
{
    struct nodoCarac *pont = lista->inicio;
    while (pont != NULL){
        printf("%c\n\n",pont->carac);
        imprimeListaNum(pont->lista);
        pont = pont->prox;
    }
    return;
}