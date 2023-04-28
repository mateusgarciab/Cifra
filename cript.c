#include <stdio.h>
#include <stdlib.h>

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
            num = posicaoAleat(lista, letra);
            if (num == -1) {
                printf("impossivel codificar mensagem\n");
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