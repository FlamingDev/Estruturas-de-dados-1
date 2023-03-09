typedef struct queue Queue;
Queue *qCreate(int n); // cria uma fila vazia
int qDestroy(Queue *q); // destr�i uma fila vazia
int qEnqueue(Queue *q, void *data); // insere um elemento na �ltima posi��o da fila
void *qDequeue(Queue *q); // Remove e retorna o elemento da primeira posi��o da fila
void *qFirst(Queue *q); // retorna, mas n�o remove o elemento da primeira posi��o da fila
int qIsEmpty(Queue *q); // retorna 1 se a fila estiver vazia, ou 0 caso contr�rio
