#include <stdlib.h>
#include "lista.h"
#define TRUE 1
#define FALSE 0

struct slnode{
	void *data;
	struct slnode *next;
};

struct sllist{
	struct slnode *first;
};

SLList *sllCreate(void){
	SLList *l = (SLList *) malloc(sizeof(SLList));
	if (l != NULL){
		l->first = NULL;
		return l;
	}
	return NULL;
}

int sllDestroy(SLList *l){
	if (l != NULL){
		if (l->first == NULL){
			free(l);
			return TRUE;
		}
	}
	return FALSE;
}

int sllPush(SLList *l, void *data){
	if (l != NULL){
		SLNode *newnode = (SLNode *) malloc(sizeof(SLNode));
		if (newnode != NULL){
			newnode->data = data;
			newnode->next = l->first;
			l->first = newnode;
			return TRUE;		
		}
	}
	return FALSE;
}

void *sllgetFirst(SLList *l){
	void *data;
	if (l != NULL){
		if (l->first != NULL){
			data = l->first->data;
			return data;
		}
	}
	return NULL;
}

void *sllPop(SLList *l){
	void *data;
	if (l != NULL){
		if (l->first != NULL){
			data = l->first->data;
			l->first = l->first->next;
			return data;
		}
	}
	return NULL;
}

void *sllGetLast(SLList *l){
	int i = 0;
	SLNode *last;
	if (l != NULL){
		if (l->first != NULL){
			last = l->first;
			while (last->next != NULL){
				last = last->next;
			}
			return last->data;
		}
	}
	return NULL;
}


SLNode *sllGetLastNode(SLList *l){
	int i = 0;
	SLNode *last;
	if (l != NULL){
		if (l->first != NULL){
			last = l->first;
			while (last->next != NULL){
				last = last->next;
			}
			return last;
		}
	}
	return NULL;
}

int sllNNodes(SLList *l){
	int i = 0;
	SLNode *last;
	if (l != NULL){
		if (l->first != NULL){
			last = l->first;
			while (last->next != NULL){
				last = last->next;
				i++;
			}
		}
		return i;
	}
	return -1;
}

int sllInsertAsLast(SLList *l, void *data){
	SLNode *newnode, *last;
	if (l != NULL){
		newnode = (SLNode *) malloc(sizeof(SLNode));
		if (newnode != NULL){
			newnode->data = data;
			newnode->next = NULL;
			last = l->first;
			if (l->first != NULL){
				while (last->next != NULL){
					last = last->next;
				}
				last->next = newnode;
			}
			else{
				l->first = newnode;
			}
			return TRUE;
		}
	}
	return FALSE;
}

void *sllRemoveLast(SLList *l){
	SLNode *last; void *data;
	if (l != NULL){
		if (l->first != NULL){
			last = l->first;
			while (last->next != NULL){
				last = last->next;
			}
			data = last->data;
			last = last->next;
			return data;
		}
	}
	return NULL;
}

int sllPromoveUltimo(SLList *l){
	SLNode *prim;
	if (l != NULL){
		if (l->first != NULL && l->first->next != NULL){
			prim = l->first;
			while (prim->next != NULL){
				prim = prim->next;
			}
			prim->next = l->first;
			l->first = prim;
			return TRUE;
		}
	}
	return FALSE;
}

int sllPunePrimeiro(SLList *l){
	void *data;
	SLNode *prim;
	if (l != NULL){
		if (l->first != NULL && l->first->next != NULL){
			prim = l->first;
			while (prim->next != NULL){
				prim = prim->next;
			}
			prim->next = l->first;
			l->first = l->first->next;
			return TRUE;
		}
	}
	return FALSE;
}

void *sllRemoveK(SLList *l, int k){
	int i = 0; SLNode *cur, *prev; void *data;
	if (l != NULL){
		if (l->first != NULL){
			cur = l->first;
			while (i < k){
				prev = cur;
				cur = cur->next;
				i++;
			}
			data = cur->data;
			prev->next = cur->next;
			return data;
		}
	}
	return NULL;
}
