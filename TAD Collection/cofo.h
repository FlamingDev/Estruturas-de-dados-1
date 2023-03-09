typedef struct cofo Cofo; // cofo é como chamaremos a coleção
Cofo *cofCreate(int numItems); // retorna um endereço para um cofo vazio
int cofInsert(Cofo *c, int item); // insere um elemento no final do vetor
int cofQuery(Cofo *c, int key); // busca por um elemento no vetor da coleção
int cofRemove(Cofo *c, int item); // remove um elemento do vetor
int cofDestroy(Cofo *c); // destrói uma coleção vazia
