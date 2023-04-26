#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "posicoes.h"
#include "listaCarac.h"

int main() {
    struct listaNum *ex;
    ex =  inicializaLista();

    srand(time(NULL));//importante botar

    insereNodoNum(ex, 1);
    insereNodoNum(ex, 2);
    insereNodoNum(ex, 3);
    insereNodoNum(ex, 4);
    insereNodoNum(ex, 5);

    printf("\n");

    imprimeListaNum(ex);

    for (int i = 0; i < 20; i++)
        printf("%d ",aleatNum(ex));

    destroilistaNum(ex);
    return 0;
}