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

    struct nodoCarac *nodo;
    nodo = alocaNodoCarac();

    destroiListaCarac(list);


    return 0;
}