#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* #include "posicoes.h" */
#include "listaCarac.h"
#include "cript.h"

FILE *abreArq(char nomeArquivo[50])
{
    FILE *arq;
    arq = fopen(nomeArquivo,"r");

    if (!arq) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    return arq;
}

FILE *criaArq(char nomeArquivo[50])
{
    FILE *arq;
    arq = fopen(nomeArquivo,"w");

    if (!arq) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    return arq;
}

int main() {
    struct listaCarac *list;
    srand(time(NULL));//importante botar

    FILE *livro = abreArq("livroCifra.txt");
    FILE *men = abreArq("mensagem.txt"); 
    FILE *codf = criaArq("menCod");
    FILE *chavesArq = criaArq("ArquivoChaves");

    list = geraArqChaves(livro, chavesArq);
    

    fclose(livro);
    fclose(men);
    fclose(codf);
    fclose(chavesArq);

    imprimeLista(list);
    destroiListaCarac(list); 
    return 0;
}