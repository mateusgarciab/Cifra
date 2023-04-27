#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* #include "posicoes.h" */
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

/*     printf("a == %d ==\n",posicaoAleat(list,'a'));
    printf("== %d ==\n",posicaoAleat(list,'a'));
    printf("== %d ==\n",posicaoAleat(list,'a'));
    printf("== %d ==\n",posicaoAleat(list,'a'));
    printf("== %d ==\n",posicaoAleat(list,'a'));
    printf("== %d ==\n",posicaoAleat(list,'a'));
    printf("b == %d ==\n",posicaoAleat(list,'b'));
    printf("== %d ==\n",posicaoAleat(list,'b'));
    printf("== %d ==\n",posicaoAleat(list,'b'));
    printf("== %d ==\n",posicaoAleat(list,'b'));
    printf("1 == %d ==\n",posicaoAleat(list,'1'));
    printf("== %d ==\n",posicaoAleat(list,'1'));
    printf("c == %d ==\n",posicaoAleat(list,'c'));
    printf("== %d ==\n",posicaoAleat(list,'c'));
    printf("== %d ==\n",posicaoAleat(list,'c'));
    printf("d == %d ==\n",posicaoAleat(list,'d'));
    printf("== %d ==\n",posicaoAleat(list,'d'));
    printf("e == %d ==\n",posicaoAleat(list,'e'));
    printf("== %d ==\n",posicaoAleat(list,'e'));
    printf("g == %d ==\n",posicaoAleat(list,'g'));
    printf("== %d ==\n",posicaoAleat(list,'g'));
    printf("== %d ==\n",posicaoAleat(list,'g')); */

    printf("a %c \n",encontraLetra(list,0));
    printf("a %c \n",encontraLetra(list,1));
    printf("a %c \n",encontraLetra(list,2));
    printf("a %c \n",encontraLetra(list,3));
    printf("a %c \n",encontraLetra(list,7));
    printf("a %c \n",encontraLetra(list,10));
    printf("a %c \n",encontraLetra(list,12));
    printf("a %c \n",encontraLetra(list,9));
    printf("a %c \n",encontraLetra(list,30));
    printf("a %c \n",encontraLetra(list,-1));

    destroiListaCarac(list);
    return 0;
}