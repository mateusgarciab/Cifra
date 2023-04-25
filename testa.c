#include <stdio.h>
#include <stdlib.h>
#include "posicoes.h"

int main() {
    struct nodoNum *ex = NULL;
    insereNodoNum(ex, 1);
    printf("%d\n", ex->valor);
    insereNodoNum(ex, 2);
    insereNodoNum(ex, 3);
    insereNodoNum(ex, 4);
    insereNodoNum(ex, 5);

    printf("%d\n", ex->valor);
    printf("%d\n", ex->prox->valor);
    printf("%d\n", ex->prox->prox->valor);
    printf("%d\n", ex->prox->prox->prox->valor);
    printf("%d\n", ex->prox->prox->prox->prox->valor);

    imprimeListaNum(ex);

    //destroilistaNum(ex);
    return 0;
}