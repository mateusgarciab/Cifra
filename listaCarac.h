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

void insereLista(struct listaCarac *lista, int valor);