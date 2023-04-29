

char devolveInicial(FILE *arq);

struct listaCarac *geraArqChaves(FILE *livro, FILE *chavesArq);

void criptografa(FILE *livro, FILE *mensOriginal, FILE *mensCodi, FILE *chavesArq);

struct listaCarac *leArqChaves(FILE *arq);

void descodificaChaves(FILE *menCod, FILE *chavesArq, FILE *menDesc);