#ifndef __POSOCOES__
#define __POSOCOES__

/* Nodo de chaves */
struct nodoNum {
    int valor;              /* Valor no do nodo */
    struct nodoNum *prox;   /* Ponteiro para o proximo nodo */
};

/* Lista de nodos  */
struct listaNum {
    struct nodoNum *inicio; /* Ponteiro para o inicio da lista */
    unsigned int tam;       /* Tamanho da lista */
};

/* Inicia a lista de numeros e o retorna */
struct listaNum *inicializaLista();

/* Aloca um nodo e o retorna */
struct nodoNum *alocaNodoNum();

/* Desaloca uma lista junto a todos os seus nodos */
void destroiListaNum(struct listaNum *lista);

/* Insere uma chave na lista passada */
void insereNodoNum(struct listaNum *lista, int valor);

/* Imprime todos os valor na saida padrao */
void imprimeListaNum(struct listaNum *lista);

/* Devolve um valor aletorio da lista passada */
int aleatNum(struct listaNum *lista);

/* Retorna 1 em caso do valor passado pertencer a lista
    retorna 0 caso contrario */
char pertence(struct listaNum *lista, int num);

#endif