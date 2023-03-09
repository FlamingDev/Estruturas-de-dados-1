#include <stdlib.h>
#include "fila.h"
#define TRUE 1
#define FALSE 0

struct queue{
	int front, rear;  
	int maxItens;
	void **item; 
};

Queue *qCreate(int maxItens){
	if (maxItens > 0){
		Queue *q = (Queue*) malloc(sizeof(Queue));
		if (q != NULL){
			q->item = (void **) malloc(sizeof(void*)*maxItens);
			if (q->item != NULL){
				q->maxItens = maxItens;
				q->front = 0;
				q->rear = -1;		
				return q;
			}
		}
		free(q);
	}
	return NULL;
}

int qDestroy(Queue *q){
	if (q != NULL){
		if (q->rear < 0){
			free(q->item);
			free(q);
			return TRUE;
		}
	}
	return FALSE;
}

int qEnqueue(Queue *q, void *data){
	if (q != NULL){
		if (q->rear < q->maxItens-1){
			q->rear++;
			q->item[q->rear] = data;
			return TRUE;
		}
	}
	return FALSE;
}


void *qDequeue(Queue *q){
	int i;
	if (q != NULL){
		if (q->rear >= 0){
			void *data = q->item[q->front];
			for (i = q->front; i < q->rear; i++){
				q->item[i] = q->item[i+1];
			}
			q->rear--;
			return data;
		}	
	}
	return NULL;
}

void *qFirst(Queue *q){
	if (q != NULL){
		if (q->rear >= 0){
			void *data = q->item[q->front];
			return data;
		}
	}
	return NULL;
}

int qIsEmpty(Queue *q){
	if (q != NULL)
		return q->rear < 0;
	return FALSE;
}

int qPromoveUltimo(Queue *q, int n){ // promove o ultimo elemento da fila em n posições
	int i,j, moves;
	void *data;
	if (q != NULL){
		if (q->rear > 0){
			data = q->item[q->rear];
			if (n < q->rear){
				moves = n;
			}	
			else{
				moves = q->rear;
			}
			j = q->rear;
			for (i = moves; i > 0; i--){
				q->item[j] = q->item[j-1];
				j--;
			}
			q->item[j] = data;
			return TRUE;
		}
	}
	return FALSE;
}

int qPunePrimeiro(Queue *q, int n){ // pune o primeiro elemento da fila em n posições
	int i,j,moves;
	void *data;
	if (q != NULL){
		if (q->rear > 0){
			data = q->item[q->front];
			if (n < q->rear){
				moves = n;
			}
			else{
				moves = q->rear;
			}
			j = q->front;
			for (i = 0; i < moves; i++){
				q->item[i] = q->item[i+1];
				j++;	
			}
			q->item[j] = data;
			return TRUE;
		}
	}
	return FALSE;
}
