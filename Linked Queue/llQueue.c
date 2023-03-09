#include "llQueue.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct slnode{
	void *data;
	struct slnode *next;
};

struct llqueue{
	struct slnode *front;
	struct slnode *rear;
};

LLQueue *llqCreate(){
	LLQueue *lq = (LLQueue *) malloc(sizeof(LLQueue));
	if (lq != NULL){
		lq->front = NULL;
		lq->rear = NULL;
		return lq;
	}
	return NULL;
}

int llqDestroy(LLQueue *lq){
	if (lq != NULL){
		if (lq->front == NULL){
			free(lq);
			return TRUE;
		}
	}
	return FALSE;
}

int llqEnqueue(LLQueue *lq, void *data){
	SLNode *last;
	if (lq != NULL){
		SLNode *newnode = (SLNode *) malloc(sizeof(SLNode));
		if (newnode != NULL){
			newnode->data = data;
			newnode->next = NULL;
			if (lq->front != NULL){
				last = lq->rear;
				last->next = newnode;			
			}
			else{
				lq->front = newnode;
			}
			lq->rear = newnode;
			return TRUE;
		}
	}
	return FALSE;
}

void *llqDequeue(LLQueue *lq){
	SLNode *first; void *data;
	if (lq != NULL){
		if (lq->front != NULL){
			first = lq->front;
			data = first->data;
			lq->front = first->next;
			if (lq->rear == first){
				lq->rear = NULL;
			}
			free(first);
			return data;
		}
	}
	return NULL;
}
