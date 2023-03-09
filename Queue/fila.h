typedef struct queue Queue;
Queue *qCreate(int n); // cria uma fila vazia
int qDestroy(Queue *q); // destrói uma fila vazia
int qEnqueue(Queue *q, void *data); // insere um elemento na última posição da fila
void *qDequeue(Queue *q); // Remove e retorna o elemento da primeira posição da fila
void *qFirst(Queue *q); // retorna, mas não remove o elemento da primeira posição da fila
int qIsEmpty(Queue *q); // retorna 1 se a fila estiver vazia, ou 0 caso contrário
