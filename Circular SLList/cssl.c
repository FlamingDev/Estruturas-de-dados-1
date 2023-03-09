#include <stdlib.h>
#include "lista circular simples.h"
#define TRUE 1
#define FALSE 0

struct cslnode{
	struct cslnode *next;
	void *data;
};

struct csllist{
	struct dlnode *first, *cur;
};

CSLList *csllCreate(){
	CSLList *l;
	l = (CSLList *) malloc(sizeof(CSLList));
	if (l != NULL){
		l->cur = NULL;
		l->first = NULL;
		return l;
	}
	return NULL;
}

int csllDestroy(CSLList *l){
	if (l != NULL){
		if (l->first == NULL){
			free(l);
			return TRUE;
		}
	}
	return FALSE;
}

int csllInsertAfterSpec(CSLList *l, void *key, void *data, int (*cmp)(void *, void *)){
	CSLNode *spec, newnode;
	if (l != NULL){
		if (l->first != NULL){
			spec = l->first;
			stat = cmp(spec->data, key);
			while (stat != TRUE && spec->next != l->first){
				spec = spec->next;
				stat = cmp(spec->data, key);
			}
			if (stat == TRUE){
				newnode = (CSLNode *) malloc(sizeof(CSLNode));
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

void *csllRemoveSpec(CSLList *l, void *data,int (*cmp)(void *, void *)){
	CSLNode *spec,*prev, *newnode; void data;
	if (l != NULL){
		if (l->first != NULL){
			prev = l->first;
			spec = prev->next;
			stat = cmp(spec->data, key);
			while (stat != TRUE && spec->next != l->first){
				prev = spec;
				spec = spec->next;
				stat = cmp(spec->data, key);
			}
			if (stat == TRUE){
				data = spec->data;
				prev->next = spec->next;
				if (l->first == spec){
					l->first = spec->next;
				}
				free(spec);
				return data;
			}
		}
	}
	return NULL;
}


