#include <stdlib.h>
#include "cFila.h"
#define TRUE 1
#define FALSE 0

struct cqueue{
	int front, rear, nElms;  
	int maxItens;
	void **item; // contém os elementos armazenados
};

cQueue *qCreate(int maxItens){
	if (max > 0){
		cQueue *q = (cQueue*) malloc(sizeof(cQueue));
		if (q != NULL){
			q->item = (void **) malloc(sizeof(void*)*max);
			if (q->item != NULL){
				q->front = 0;
				q->rear = -1;
				q->nElms = 0;
				q->maxItens = maxItens;
				return q;
			}
		}
		free(q);
	}
	return NULL;
}

int qDestroy(cQueue *q){
	if (q != NULL){
		if (q->nElms <= 0){
			free(q->item);
			free(q);
			return TRUE;
		}
	}
	return FALSE;
}

int qEnqueue(cQueue *q, void *data){
	if (q != NULL){
		if (q->nElms < q->maxItens){
			q->rear = incCirc(q->rear, q->maxItens);
			q->item[q->rear] = data;
			q->nElms++;
			return TRUE;
		}
	}
	return FALSE;
}

void *qDequeue(cQueue *q){
	int i;
	void *data;
	if (q != NULL){
		if (q->nElms > 0){
			data = q->item[q->front];
			q->front = incCirc(q->front, q->maxItens);
			return data;
		}
	}
	return NULL;
}

int incCirc(int i, int max){
	if (i == max-1){
		return 0;
	}
	else{
		return i+1;
	}
}

int decCirc(int i, int max){
	if (i == 0){
		return max-1;
	}
	else{
		return i-1;
	}
}

void *qFirst(cQueue *q){
	if (q != NULL){
		if (q->rear >= 0){
			return q->item[q->front];
		}
	}
	return NULL;
}

int qIsEmpty(cQueue *q){
	if (q != NULL){
		if (q->nElms < 0){
			return TRUE;
		}
	}
	return FALSE;
}

int cqPuneFuraFila(cQueue *q){
	int i,j, next_j, moves;
	void *data;
	if (q != NULL){
		if (q->nElms > 1){
			data = q->item[q->front];
			j = q->front;
			moves = ceil(q->nElms/2);
			for (i = moves; i > 0; i = decCirc(i,q->maxItens)){
				next_j = incCirc(j,q->maxItens);
				q->item[j] = q->item[next_j];
				j = next_j;
			}
			q->item[j] = data;
			return TRUE;
		}
	}
	return FALSE;
}

int cqPunePrimeiro(cQueue *q, int n){
	int i,j, moves, prev_j;
	void *data;
	if (q != NULL){
		if (q->nElms > 0){
			data = q->item[q->front];
			if (n < q->nElms){
				moves = n;
			}	
			else{
				moves = q->nElms;
			}
			j = q->front;
			for (i = moves; i > 0; i = decCirc(i,q->maxItens)){
				prev_j = incCirc(prev_j,q->maxItens);
				q->item[j] = q->item[prev_j];
				j = prev_j;
			}
			q->item[j] = data;
			return TRUE;
		}
	}
	return FALSE;
}
