typedef struct gcofo gCofo;
typedef struct aluno Aluno;
gCofo *gcofCreate(int maxItens); // cria e retorna o endere�o para uma estrutura cofo
int gcofInsert(gCofo *c, void *item); // insere no final do vetor 
void *gcofRemove(gCofo *c, void *key,int (*cmp)(void *a, void *b)); // remove e retorna um dado especificado, ou retorna NULL
void *gcofQuery(gCofo *c, void *key,int (*cmp)(void *a, void *b)); // retorna um dado especificado, ou NULL
void *gcofGetFirst(gCofo *c); // retorna o primeiro dado do vetor
void *gcofGetNext(gCofo *c); // retorna o pr�ximo dado do vetor, indicado por cur
int esvaziaCofo(gCofo *c); // esvazia o cofo
int gcofDestroy(gCofo *c); // destr�i um cofo vazio
int isEmpty(gCofo *c); // verifica se o vetor est� vazio ou n�o
