struct nodoCarac {
    char carac;
    struct nodoCarac *prox;
    struct listaNum *lista;
};

struct listaCarac {
    struct nodoCarac *inicio;
};

struct listaCarac *iniciaLiastaCarac();

struct nodoCarac *alocaNodoCarac();

void insereNodoCarac(struct listaCarac *lista, struct nodoCarac *nodo);

void destroiListaCarac(struct listaCarac *lista);