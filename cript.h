#ifndef __CRIP__
#define __CRIP__

/* Devolve a primeira letra e reposisiona para a proroxima
    Em caso do pimeiro caracter nao ser uma letra ou caracter valido devolve -1 */
char devolveInicial(FILE *arq);

/* Escreve no arquivo de chaves na tabulacao especificada a partir do livro de chaves
    Retorna a lista de caracteres usada para criação do arquivo de chaves */
struct listaCarac *geraArqChaves(FILE *livro, FILE *chavesArq);

/* Escreve a mensagem codificada e o arquivo de chaves a partir do livro cifra e da mensagem original */
void criptografa(FILE *livro, FILE *mensOriginal, FILE *mensCodi, FILE *chavesArq);

/* Le um arquivo de chaves e retorna uma lista de chaves com o conteudo do arquivo */
struct listaCarac *leArqChaves(FILE *arq);

/* Descodifica e grava a mensagem descrodificada a partir da mensagem codificada e arquivo de chaves */
void descodificaChaves(FILE *menCod, FILE *chavesArq, FILE *menDesc);

/* Descodifica e grava a mensagem descrodificada a partir da mensagem codificada e livro cifra */
void descodificaLivro(FILE *menCod, FILE *livro, FILE *menDesc);

#endif