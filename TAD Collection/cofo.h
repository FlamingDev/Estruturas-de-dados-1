typedef struct cofo Cofo; // cofo � como chamaremos a cole��o
Cofo *cofCreate(int numItems); // retorna um endere�o para um cofo vazio
int cofInsert(Cofo *c, int item); // insere um elemento no final do vetor
int cofQuery(Cofo *c, int key); // busca por um elemento no vetor da cole��o
int cofRemove(Cofo *c, int item); // remove um elemento do vetor
int cofDestroy(Cofo *c); // destr�i uma cole��o vazia
