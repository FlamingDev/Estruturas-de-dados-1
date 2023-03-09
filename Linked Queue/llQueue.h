typedef struct llqueue LLQueue;
typedef struct slnode SLNode;
LLQueue *llqCreate(); // cria e retorna o endere�o pra uma fila
int llqEnqueue(LLQueue *lq, void *data); // insere um elemento no final da fila
int llqDequeue(LLQueue *lq); // remove o elemento do in�cio da fila
int llqDestroy(LLQueue *lq); // destr�i uma fila vazia

