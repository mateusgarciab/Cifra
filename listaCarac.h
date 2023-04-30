#ifndef __LISTA__
#define __LISTA__

/* Nodo da lista de letra */
struct nodoCarac {
    char carac;                 /* Caracter no nodo */
    struct nodoCarac *prox;     /* Ponteiro para o proximo nodo da lista */
    struct listaNum *lista;     /* Ponteiro para lista de chaves no nodo */
};

/* Lista de nodos */
struct listaCarac {
    struct nodoCarac *inicio;   /* Ponteiro para o inicio da lista */
};

/* Inicia a lista de caracteres e retorna um ponteiro para a mesma */
struct listaCarac *iniciaLiastaCarac();

/* Aloca um nodo e retorna um ponteiro para o mesmo */
struct nodoCarac *alocaNodoCarac();

/* Em caso do nodo com a letra existir o numero eh  colocado em sua lista de chaves
    caso contrario o nodo eh criado e o numero eh colocado na sua lista */
void insereNodoCarac(struct listaCarac *lista, char letra, int num);

/* Desaloca a lista de caracteres passada e seus nodos */
void destroiListaCarac(struct listaCarac *lista);

/* Imprime na saida Padrao a lista de caracteres passada */
void imprimeLista(struct listaCarac *lista);

/* Devolve uma chave aleatoria da lsita de chaves de um desterminado caracter
    caso esse caracter nao exista retorna -1 */
int posicaoAleat(struct listaCarac *lista, char letra);

/* Retorna a letra na qual tem em sua lista de chaves o numero passado
    caso nao exista esse numero em nenhuma lista retorna -1 */
char encontraLetra(struct listaCarac *lista, int num);

/* Escreve em um arquivo o caracter de um nodo e todas as suas chaves */
void escreveNodo(FILE *arq, struct nodoCarac *nodo);

#endif