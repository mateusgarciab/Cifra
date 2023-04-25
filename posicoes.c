#include <stdio.h>
#include <stdlib.h>

#include "posicoes.h"

struct nodoNum *alocaNodoNum()
{
    struct nodoNum *novo = malloc(sizeof(struct nodoNum));
    if (!novo)
        return NULL;

    return novo;
}