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

void insereNodoCarac(struct listaCarac *lista, char letra, int num);

void destroiListaCarac(struct listaCarac *lista);

void imprimeLista(struct listaCarac *lista);

int posicaoAleat(struct listaCarac *lista, char letra);

char encontraLetra(struct listaCarac *lista, int num);