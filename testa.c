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
    insereNodoCarac(list, 'b', 4);
    insereNodoCarac(list, 'b', 5);
    insereNodoCarac(list, 'c', 6);
    insereNodoCarac(list, 'a', 7);
    insereNodoCarac(list, 'e', 8);
    insereNodoCarac(list, 'g', 9);
    insereNodoCarac(list, 'c', 10);
    insereNodoCarac(list, '1', 11);
    insereNodoCarac(list, 'g', 12);
    /* nodo-> */

    imprimeLista(list);

    destroiListaCarac(list);
    return 0;
}