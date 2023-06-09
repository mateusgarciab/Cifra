#include <stdio.h>
#include <stdlib.h>

#include "listaCarac.h"

char devolveInicial(FILE *arq)
{
    char letra, lixo;
    fscanf(arq,"%c", &letra);
    if ((feof(arq))|| (letra < '!') || (letra > '~'))
        return -1;

    fscanf(arq,"%c", &lixo);
    while ((!feof(arq)) && (lixo != '\n') && (lixo != '\0') && (lixo != ' ')) {
        fscanf(arq,"%c", &lixo);
    
    }

    if ((letra >= 'A') && (letra <= 'Z'))
        return letra + 32;
    
    return letra;
}

void escreveArqChaves(struct listaCarac *lista, FILE *chavesArq)
{
    struct nodoCarac *nodo = lista->inicio;
    if (nodo == NULL)
        return;

    escreveNodo(chavesArq, nodo);
    while(nodo->prox != NULL) {
        fprintf(chavesArq, "\n");
        nodo = nodo->prox;
        escreveNodo(chavesArq, nodo);    
    }

    return;
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


void criptografa(FILE *livro, FILE *mensOriginal, FILE *mensCodi, FILE *chavesArq)
{
    struct listaCarac *lista = geraArqChaves(livro, chavesArq);
    int num;
    char letra;

    fscanf(mensOriginal, "%c", &letra);
    while (!feof(mensOriginal)) {
        if ((letra == ' ') || (letra == '\n')) {
            fprintf(mensCodi, "%d ", -1);
        } else {
            if ((letra >= 'A') && (letra <= 'Z'))
                letra += 32;
            num = posicaoAleat(lista, letra);
            if (num == -1) {
                printf("impossivel codificar mensagem %c\n",letra);
                exit(1);
            }
            fprintf(mensCodi, "%d ", num);
        }
        fscanf(mensOriginal, "%c", &letra);
    }

    destroiListaCarac(lista);
} 

struct listaCarac *leArqChaves(FILE *arq)
{
    struct listaCarac *lista = iniciaLiastaCarac();
    char lixo, letra;
    int num;

    while (!feof(arq)) {
        fscanf(arq, "%c",&letra);
        fscanf(arq, "%c",&lixo);
        fscanf(arq, "%c",&lixo);

        fscanf(arq, "%d",&num);
        insereNodoCarac(lista, letra, num);
        fscanf(arq, "%c",&lixo);
        while ((!feof(arq)) && (lixo != '\n')){
            fscanf(arq, "%d",&num);
            insereNodoCarac(lista, letra, num);
            fscanf(arq, "%c",&lixo);
        }
    }

    return lista;
}

void descodificaChaves(FILE *menCod, FILE *chavesArq, FILE *menDesc)
{
    struct listaCarac *lista = leArqChaves(chavesArq);
    char lixo, letra;
    int num;

    fscanf(menCod, "%d", &num);
    while (!feof(menCod)) {
        if (num == -1) {
            fprintf(menDesc," ");
        } else {
            letra = encontraLetra(lista, num);
            if (letra == -1)
                fprintf(menDesc," ");
            else
                fprintf(menDesc, "%c", letra);
        }
        fscanf(menCod, "%c", &lixo);
        fscanf(menCod, "%d", &num);
    }

    destroiListaCarac(lista);
    return;
}

void descodificaLivro(FILE *menCod, FILE *livro, FILE *menDesc)
{
    struct listaCarac *lista = iniciaLiastaCarac();
    int num, i = 0;
    char lixo, letra;
    while (!feof(livro)){
        letra = devolveInicial(livro);
        if (letra != -1) {
            insereNodoCarac(lista, letra, i);
            i++;
        }
    }

    fscanf(menCod, "%d", &num);
    while (!feof(menCod)) {
        if (num == -1) {
            fprintf(menDesc," ");
        } else {
            letra = encontraLetra(lista, num);
            if (letra == -1)
                fprintf(menDesc," ");
            else
                fprintf(menDesc, "%c", letra);
        }
        fscanf(menCod, "%c", &lixo);
        fscanf(menCod, "%d", &num);
    }

    destroiListaCarac(lista);
    return;
}