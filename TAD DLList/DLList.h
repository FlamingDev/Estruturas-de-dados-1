typedef struct dlnode DLNode;
typedef struct dllist DLList;
typedef struct aluno Aluno;
DLList *dllCreate(); // cria e retorna o endereço para uma lista encadeada
int dllDestroy(DLList *l); // destrói uma lista vazia. Retorna TRUE ou FALSE
int dllPush(DLList *l, void *data); // insere um elemento no início da lista. Retorna TRUE ou FALSE
void *dllPop(DLList *l); // remove o elemento do início da lista. Retorna o elemento removido, ou NULL
void *dllGet(DLList *l, int index); // retorna o elemento no índice indicado, seguindo a ordem natural da lista.
int isEmpty(DLList *l); // verifica se a lista está vazia ou não. Retorna TRUE ou FALSE
int dllInsertAsLast(DLList *l, void *data); // insere no final da lista. Retorna TRUE ou FALSE
int dllInsertAfterSpec(DLList *l, void *data, void *key, int (*cmp)(void *, void *)); // insere um elemento logo após um dado especificado. Retorna TRUE ou FALSE
int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));  // insere um elemento antes de um dado especificado. Retorna TRUE ou FALSE
void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *)); // remove um dado especificado, se o achar na lista. Retorna o dado removido, ou NULL
void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *)); // consulta se um dado especificado está na lista. Retorna o dado se for achado, ou NULL caso contrário
int dllNElms(DLList *l); // retorna o número de elementos da lista encadeada
int dllRemoveAll(DLList *l); // remove todos os elementos da lista. Retorna TRUE ou FAlSE
