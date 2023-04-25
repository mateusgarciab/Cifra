struct nodoNum {
    int valor;
    struct nodoNum *prox;
};

struct nodoNum *alocaNodoNum();

void destroilistaNum(struct nodoNum *raiz);

void insereNodoNum(struct nodoNum *raiz, int valor);

void imprimeListaNum(struct nodoNum *raiz);