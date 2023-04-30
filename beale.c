#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>

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
    srand(time(NULL));

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

    while ((option = getopt (argc, argv, "b:c:dei:m:o:")) != -1)
        switch (option) {
        case 'b': 
            flag_b = 1;
            value_b = optarg;
            break;
        case 'c': 
            flag_c = 1;
            value_c = optarg;
            break;
        case 'd': 
            flag_d = 1;
            break;
        case 'e': 
            flag_e = 1;
            break;
        case 'i': 
            flag_i = 1;
            value_i = optarg;
            break;
        case 'm': 
            flag_m = 1;
            value_m = optarg;
            break;
        case 'o': 
            flag_o = 1;
            value_o = optarg;
            break;        
        default:
            fprintf (stderr, "Uso incorreto: %s\n", argv[0]);
            printf("Possiveis usos\n./beale -e -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves\n");
	        printf("./beale -d -i MensagemCodificada -c ArquivoDeChaves -o MensagemDecodificada\n./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada \n");
            exit (1) ;
    }

    if((flag_e == 1) && (flag_b == 1) && (flag_m == 1) && (flag_o == 1) && (flag_c == 1)){
        //codifica
        FILE *livro = abreArq(value_b);
        FILE *men = abreArq(value_m);
        FILE *codf = criaArq(value_o);
        FILE *chavesArq = criaArq(value_c);
        criptografa(livro, men, codf, chavesArq);
        fclose(livro);
        fclose(men);
        fclose(codf);
        fclose(chavesArq);
    } else if ((flag_d == 1) && (flag_i == 1) && (flag_c == 1) && (flag_o == 1)) {
        //descofica chaves
        FILE *codf = abreArq(value_i);
        FILE *chavesArq = abreArq(value_c);
        FILE *menDesc = criaArq(value_o);
        descodificaChaves(codf, chavesArq, menDesc);
        fclose(codf);
        fclose(chavesArq);
        fclose(menDesc);
    } else if ((flag_d == 1) && (flag_i == 1) && (flag_b == 1) && (flag_o == 1)) {
        //descofica livro
        FILE *codf = abreArq(value_i);
        FILE *livro = abreArq(value_b);
        FILE *menDesc = criaArq(value_o);
        descodificaLivro(codf, livro, menDesc);
        fclose(codf);
        fclose(livro);
        fclose(menDesc);
    } else {
        printf("Uso incorreto\nPossiveis usos\n./beale -e -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves\n");
        printf("./beale -d -i MensagemCodificada -c ArquivoDeChaves -o MensagemDecodificada\n./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada \n");
        exit (1) ;
    }

    return 0;
}