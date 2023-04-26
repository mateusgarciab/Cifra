
struct nodoNum {
    int valor;
    struct nodoNum *prox;
};

struct listaNum {
    struct nodoNum *inicio;
    unsigned int tam;
};

struct listaNum *inicializaLista();

struct nodoNum *alocaNodoNum();

void destroiListaNum(struct listaNum *lista);

void insereNodoNum(struct listaNum *lista, int valor);

void imprimeListaNum(struct listaNum *lista);

int aleatNum(struct listaNum *lista);