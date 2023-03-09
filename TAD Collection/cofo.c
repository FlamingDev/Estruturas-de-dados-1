#include <stdlib.h>
#include <stdio.h>
#include "cofo.h"
#define TRUE 1
#define FALSE 0

struct cofo{
	int numItems;
	int maxItems;
	int *item; 
};


Cofo *cofCreate(int maxItems){ // retorna o cofo vazio criado
	if (maxItems > 0){
		Cofo *c = (Cofo *) malloc(sizeof(Cofo));
		if (c != NULL){
			c->item = (int *) malloc(maxItems * sizeof(int));
			if (c->item != NULL){
				c->numItems = 0;
				c->maxItems = maxItems;
				return c;
			}
		}
		free(c);
	}
	return NULL;
}

int cofInsert(Cofo *c, int item){ // adiciona um novo item ao cofo
	if (c != NULL && c->numItems < c->maxItems){
		c->item[c->numItems] = item;
		c->numItems++;
		return TRUE;
	}
	return FALSE;
}

int cofRemove(Cofo *c, int item){
	int i,j;
	if (c != NULL && c->numItems > 0){
		for (i = 0; i < c->numItems; i++){
			if (c->item[i] == item){
				for (j = i; j < c->numItems; j++){
					c->item[j] = c->item[j+1];
				}
				c->numItems--;
				return c->item[i];
			}			
		}
	}
	return FALSE;
}

int cofQuery(Cofo *c, int key){ // procura um item dentro do cofo
	int i;
	if (c != NULL){
		for (i = 0; i < c->numItems; i++){
			if (c->item[i] == key){
				return i;
			}
		}
	}
	return FALSE;
}

int cofDestroy(Cofo *c){ // destroi o cofo se ele estiver vazio
	if (c != NULL && c->numItems == 0){
		free(c->item);
		free(c);
		return TRUE;
	}
	return FALSE;
}

int cofIsEmpty(Cofo *c){
	return c->numItems <= 0;
}







