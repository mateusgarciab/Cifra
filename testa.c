#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* #include "posicoes.h" */
/* #include "listaCarac.h" */
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

int main(int argc, char **argv) {
    /* struct listaCarac *list; */
    srand(time(NULL));//importante botar


    int flag_b = 0;
    int flag_c = 0;
    int flag_d = 0;
    int flag_e = 0;
    int flag_i = 0;
    int flag_m = 0;
    int flag_o = 0;

    char *value_b = NULL;
    char *value_c = NULL;
    char *value_i = NULL;
    char *value_m = NULL;
    char *value_o = NULL;
    int option;

    opterr = 0;

    while ((option = getopt (argc, argv, "b:c:dei:m:o:")) != -1)
        switch (option) {
        case 'b': 
            flag_b = 1;
            break;
        case 'c': 
            flag_c = 1;
            break;
        case 'd': 
            flag_d = 1;
            break;
        case 'e': 
            flag_e = 1;
            break;
        case 'i': 
            flag_i = 1;
            break;
        case 'm': 
            flag_m = 1;
            break;
        case 'o': 
            flag_o = 1;
            break;


        case 'c':      // option -c was set with value
            value_c = optarg;
            break;
        
        
        default:
            fprintf (stderr, "Usage: %s -a -b -c value\n", argv[0]);
	        exit (1) ;
      }


























    FILE *livro = abreArq("livroCifra.txt");
    FILE *men = abreArq("mensagem.txt"); 
    FILE *codf = abreArq("menCod");
    FILE *chavesArq = abreArq("ArquivoChaves");
    FILE *menDesc = criaArq("menDesc");

    /* list = geraArqChaves(livro, chavesArq);  */
    
/*     criptografa(livro, men, codf, chavesArq); 

    list = leArqChaves(chavesArq); */

    /* descodificaChaves(codf, chavesArq, menDesc); */

    descodificaLivro(codf, livro, menDesc);

    fclose(livro);
    fclose(men);
    fclose(codf);
    fclose(chavesArq);
    fclose(menDesc);

/*     imprimeLista(list);
    destroiListaCarac(list); */
    return 0;
}