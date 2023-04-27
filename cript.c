#include <stdio.h>

#include "listaCarac.h"

char devolveInicial(FILE *arq)
{
    char letra, lixo;
    fscanf(arq,"%c", &letra);
    if ((letra < '!') || (letra > '~'))
        return -1;

    fscanf(arq,"%c", &lixo);
    while ((!feof(arq)) && (lixo != '\n') && (lixo != '\0') && (lixo != ' ')) {//talvez de problema de passar do fim do arquivo
        fscanf(arq,"%c", &lixo);
    
    }

    if ((letra >= 'A') && (letra <= 'Z'))
        return letra + 32;
    
    return letra;
}

void escreveArqChaves(struct listaCarac *lista, FILE *chavesArq)
{
    struct nodoCarac *nodo = lista->inicio;
    while(nodo != NULL) {
        fprintf(chavesArq,"%c:", nodo->carac);
    }
} 

struct listaCarac *geraArqChaves(FILE *livro , FILE *chavesArq) 
{
    struct listaCarac *lista = iniciaLiastaCarac();
    int i = 0;
    char letra;
    while (!feof(livro)){
        letra = devolveInicial(livro);
        if (letra != -1) {
            insereNodoCarac(lista, letra, i);
            i++;
        }
    }

    escreveArqChaves(lista, chavesArq);

    return lista;
}

/* 
void criptografa(FILE *livro, FILE *mensOriginal, FILE *mensCodi, FILE *chavesArq)
{
    gera chaves
} */