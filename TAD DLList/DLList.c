#include <stdlib.h>
#include <stdio.h>
#include "Lista dupla.h"
#define TRUE 1 
#define FALSE 0

struct dlnode{
	struct dlnode *next, *prev;
	void *data;
};

struct dllist{
	struct dlnode *first, *cur;
};

struct aluno{
	char nome[30];
	int id;
	float nota;
};

DLList *dllCreate(){
	DLList *l;
	l = (DLList *) malloc(sizeof(DLList));
	if (l != NULL){
		l->first = NULL;
		l->cur = NULL;
		return l;
	}
	return NULL;
}

int dllDestroy(DLList *l){
	if (l != NULL){
		if (l->first == NULL){
			free(l);
			return TRUE;
		}
	}
	return FALSE;
}

int dllPush(DLList *l, void *data){
	DLNode *newnode;
	if (l != NULL){
		newnode = (DLNode *) malloc(sizeof(DLNode));
		if (newnode != NULL){
			newnode->data = data;
			newnode->prev = NULL;
			newnode->next = l->first;
			if (l->first != NULL){
				l->first->prev = newnode;
			}
			l->first = newnode;
			return TRUE;
		}
	}
	return FALSE;
}

void *dllPop(DLList *l){
	DLNode *nextnode, *first; void *data;
	if (l != NULL){
		if (l->first != NULL){
			first = l->first;
			data = first->data;
			nextnode = first->next;
			if (nextnode != NULL){
				nextnode->prev = NULL;
			}
			l->first = nextnode;
			free(first);
			return data;
		}
	}
}

int dllInsertAsLast(DLList *l, void *data){
	DLNode *newnode, *last;
	if (l != NULL){
		newnode = (DLNode *) malloc(sizeof(DLNode));
		if (newnode != NULL){
			newnode->data = data;
			newnode->next = NULL;	
			if (l->first == NULL){
				l->first = newnode;
				l->first->prev = NULL;
			}
			else{
				last = l->first;
				while (last->next != NULL){
					last = last->next;
				}
				last->next = newnode;
				newnode->prev = last;
			}
			return TRUE;
		}
	}
	return FALSE;
}

void *dllGet(DLList *l, int index){
	DLNode *spec; int i = 0;
	if (l != NULL){
		if (l->first != NULL){
			spec = l->first;
			while (spec->next != NULL && i != index){
				spec = spec->next;
				i++;
			}
			return spec->data;
		}
	}
	return NULL;
}

int dllInsertAfterSpec(DLList *l, void *data, void *key, int (*cmp)(void *, void *)){
	DLNode *spec, *newnode, *prevnode, *nextnode; int stat;
	if (l != NULL){
		if (l->first != NULL){
			newnode = (DLNode *) malloc(sizeof(DLNode));
			if (newnode != NULL){
				newnode->data = data;
				spec = l->first;
				stat = cmp(spec->data, key);
				while (spec->next != NULL && stat != TRUE){
					spec = spec->next;
					stat = cmp(spec->data, key);
				}
				if (stat == TRUE){
					nextnode = spec->next;
					newnode->prev = spec;
					newnode->next = nextnode;
					spec->next = newnode;
					if (nextnode != NULL){
						nextnode->prev = newnode;
					}
					return TRUE;
				}
			}	
		}
	}
	return FALSE;
}

int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *)){
	DLNode *spec, *newnode, *prevnode, *nextnode; int stat;
	if (l != NULL){
		if (l->first != NULL){
			spec = l->first;
			stat = cmp(spec->data, key);
			while (spec->next != NULL && stat != TRUE){
				spec = spec->next;
				stat = cmp(spec->data, key);
			}
			if (stat == TRUE){
				newnode = (DLNode *) malloc(sizeof(DLNode));
				if (newnode != NULL){
					newnode->data = data;
					newnode->next = spec;
					newnode->prev = prevnode;
					prevnode = spec->prev;
					if (prevnode != NULL){
						prevnode->next = newnode;
					}
					else{
						l->first = newnode;
					}
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *)){
	DLNode *spec, *prevnode, *nextnode; int stat; void *data;
	if (l != NULL){
		if (l->first != NULL){
			spec = l->first;
			stat = cmp(spec->data, key);
			while (spec->next != NULL && stat != TRUE){
				spec = spec->next;
				stat = cmp(spec->data, key);
			}
			if (stat == TRUE){
				data = spec->data;
				prevnode = spec->prev;
				nextnode = spec->next;
				if (prevnode != NULL){
					prevnode->next = nextnode;
				}
				else{
					l->first = nextnode;
				}
				if (nextnode != NULL){
					nextnode->prev = prevnode;
				}
				free(spec);
				return data;
			}
		}
	}
	return NULL;
}

void removeMenores(DLList *l, void *key, int (*cmp)(void *, void*)){
	DLNode *cur, *prevnode, *nextnode; int stat;
	if (l != NULL){
		if (l->first != NULL){
			cur = l->first;
			while (cur->next != NULL){
				stat = cmp(cur->data,key);
				prevnode = cur->prev;
				nextnode = cur->next;
				if (stat == -1){
					if (prevnode != NULL){
						prevnode->next = nextnode;
					}
					else{
						l->first = nextnode;
					}
				}
				cur = cur->next;
			}
		}
	}
}

void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *)){
	DLNode *cur; int stat;
	if (l != NULL){
		if (l->first != NULL){
			cur = l->first;
			stat = cmp(cur->data,key);
			while (cur->next != NULL && stat != TRUE){
				cur = cur->next;
				stat = cmp(cur->data,key);
			}
			if (stat == TRUE){
				return cur->data;
			}		
		}
	}
	return NULL;
}

int dllRemoveAll(DLList *l){
	DLNode *cur, *prev;
	if (l != NULL){
		if (l->first != NULL){
			cur = l->first;
			while (cur->next != NULL){
				prev = cur;		
				cur = cur->next;
				free(prev);
			}
			l->first = NULL;
			return TRUE;
		}
	}
	return FALSE;
}

int dllNElms(DLList *l){
	DLNode *cur; int count;
	if (l != NULL){
		if (l->first != NULL){
			count = 1;
			cur = l->first;
			while (cur->next != NULL){
				cur = cur->next;
				count++;
			}
			return count;
		}
		return 0;
	}
	return -1;
}

int isEmpty(DLList *l){
	if (l != NULL){
		return l->first == NULL;
	}
}

int QueryAlunoNota(void *a, void *b){
	Aluno *pa;
 	float *pnota;
	pa = (Aluno *)a;
	pnota = (float *)b;
	if (pa->nota == *pnota){
		return TRUE;
	}
	return FALSE;
}

int QueryAlunoNome(void *a, void *b){
	Aluno *pa;
 	char *pnome;
	pa = (Aluno *)a;
	pnome = (char *)b;
	if (!strcmp(pa->nome,pnome)){
		return TRUE;
	}
	return FALSE;
}

int QueryAlunoID(void *a, void *b){
	Aluno *pa;
 	int *pID;
	pa = (Aluno *)a;
	pID = (int *)b;
	if (pa->id == *pID){
		return TRUE;
	}
	return FALSE;
}
