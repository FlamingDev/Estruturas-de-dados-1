typedef struct llqueue LLQueue;
typedef struct slnode SLNode;
LLQueue *llqCreate(); // cria e retorna o endereço pra uma fila
int llqEnqueue(LLQueue *lq, void *data); // insere um elemento no final da fila
int llqDequeue(LLQueue *lq); // remove o elemento do início da fila
int llqDestroy(LLQueue *lq); // destrói uma fila vazia

