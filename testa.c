#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* #include "posicoes.h" */
#include "listaCarac.h"
#include "cript.h"

FILE *abreArq(char nomeArquivo[])
{
    FILE *arq;
    arq = fopen(nomeArquivo,"r");

    if (!arq) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    return arq;
}

FILE *criaArq(char nomeArquivo[])
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
    /* struct listaCarac *list; */
    srand(time(NULL));//importante botar

    FILE *livro = abreArq("livroCifra.txt");
    FILE *men = abreArq("mensagem.txt"); 
    FILE *codf = abreArq("menCod");
    FILE *chavesArq = abreArq("ArquivoChaves");
    FILE *menDesc = criaArq("menDesc");

    /* list = geraArqChaves(livro, chavesArq);  */
    
/*     criptografa(livro, men, codf, chavesArq); 

    list = leArqChaves(chavesArq); */

    descodificaChaves(codf, chavesArq, menDesc);

    fclose(livro);
    fclose(men);
    fclose(codf);
    fclose(chavesArq);
    fclose(menDesc);

/*     imprimeLista(list);
    destroiListaCarac(list); */
    return 0;
}