#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "posicoes.h"
#include "listaCarac.h"

int main() {
    /* struct listaNum *ex; */
    struct listaCarac *list;
   /*  ex =  inicializaLista(); */
    srand(time(NULL));//importante botar

    list = iniciaLiastaCarac();

    insereNodoCarac(list, 'a', 0);
    insereNodoCarac(list, 'a', 1);
    insereNodoCarac(list, 'a', 2);
    insereNodoCarac(list, 'd', 3);
    printf("%c\n",list->inicio->carac);
    imprimeListaNum(list->inicio->lista);
    printf("%c\n",list->inicio->prox->carac);
    imprimeListaNum(list->inicio->prox->lista);
    insereNodoCarac(list, 'b', 4);
    insereNodoCarac(list, 'b', 5);
    insereNodoCarac(list, 'c', 6);
    /* nodo-> */

    destroiListaCarac(list);
    return 0;
}