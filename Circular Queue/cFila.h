/*   Fila circular: vamos forçar rear a usar o espaço liberado por front
   - Função para incremento e decremento   */
typedef struct cqueue cQueue;
cQueue *qCreate(int n);
int qDestroy(cQueue *q);
int qEnqueue(cQueue *q, void *data);
void *qDequeue(cQueue *q);
int incCirc(int i, int max);
int decCirc(int i, int max);
void *qFirst(cQueue *q);
int qIsEmpty(cQueue *q);
