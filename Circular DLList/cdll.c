#include <stdlib.h>
#include "cdll.h"
#define TRUE 1
#define FALSE 0

struct cdlnode{
	struct dlnode *next, *prev;
	void * data;
};

struct cdllist{
	struct dlnode *first, *cur;
};

CDLList *cdllCreate(){
	CDLList *l;
	l = (CDLList *) malloc(sizeof(CDLList));
	if (l != NULL){
		l->first = NULL;
		l->cur = NULL;
		return l;
	}
	return NULL;
}

int cdllDestroy(CDLList *l){
	if (l != NULL){
		if (l->first == NULL){
			free(l);
			return TRUE;
		}
	}
	return FALSE;
}

int cdllInsertAfterSpec(CDLList *l, void *key, void *data, int (*cmp)(void *, void *)){
	DLNode *spec, *newnode; int stat;
	if (l != NULL){
		if (l->first != NULL){
			spec = l->first;
			stat = cmp(spec->data,key);
			while (spec->next != l->first && stat != TRUE){
				spec = spec->next;
				stat = cmp(spec,key);
			}
			if (stat == TRUE){
				newnode = (DLNode *) malloc(sizeof(DLNode));
				if (newnode != NULL){
					newnode->data = data;
					newnode->next = spec->next;
					spec->next = newnode;
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

int RemoveSpecEVizinhos(DLList *l, void *key, int (*cmp)(void *, void *)){
	DLNode *spec, *prevnode, *nextnode, *prevdoprev, *nextdonext; int stat;
	if (l != NULL){
		if (l->first != NULL){
			spec = l->first;
			stat = cmp(spec->data, key);
			while (stat != TRUE && spec->next != l->first){
				spec = spec->next;
				stat = cmp(spec->data, key);
			}
			if (stat == TRUE){
				prevnode = spec->prev;
				prevdoprev = spec->prev->prev;
				nextnode = spec->next;
				nextdonext = spec->next->next;
				if (prevnode != l->first){
					prevdoprev->next = nextdonext;
				}
				else{
					l->first = nextdonext;
				}
				
			}
		}
	}
	return NULL;
}
