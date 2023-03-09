typedef struct slnode SLNode;
typedef struct sllist SLList;
SLList *sllCreate(void); // cria e retorna um endereço para lista, ou NULL
int sllPush(SLList *l, void *data); // insere um elemento como primeiro da lista
void *sllGetFirst(SLList *l); // retorna o primeiro elemento da lista, ou NULL
void *sllPop(SLList *l); // remove o primeiro elemento da lista
int sllDestroy(SLList *l); // destrói uma lista vazia
int sllInsertAsLast(SLList *l, void *data); // insere um elemento como último
int sllNNodes(SLList *l); // retorna o número de nós da lista
void *sllRemoveLast(SLList *l); // remove o último elemento da lista
