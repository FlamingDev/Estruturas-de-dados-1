#include <stdlib.h>
#include <string.h>
#include "gCofo.h"
#define TRUE 1
#define FALSE 0
#include "gCofo.h"

struct gcofo{
	int numItens;
	int maxItens;
	int cur;
	void **item;
};

struct aluno{
	char nome[30];
	int id;
	float nota;
};

gCofo *gcofCreate(int maxItens){
	if (maxItens > 0){
		gCofo* gc = (gCofo *) malloc(sizeof(gCofo));
		if (gc != NULL){
			gc->item = (void **) malloc(maxItens * sizeof(void*));
			if (gc->item != NULL){
				gc->cur = -1;
				gc->maxItens = maxItens;
				gc->numItens = 0;
				return gc;
			}
			free(gc->item);
		}
		free(gc);
	}
	return NULL;
}

int gcofDestroy(gCofo *gc){
	if (gc != NULL){
		if (gc->numItens <= 0){
			free(gc->item);
			free(gc);
			return TRUE;
		}
	}
	return FALSE;
}

int gcofInsert(gCofo *gc, void *item){
	if (gc != NULL){
		if (gc->numItens < gc->maxItens){
			gc->item[gc->numItens] = item;
			gc->numItens++;
			return TRUE;
		}
	}
	return FALSE;
}



void *gcofGetFirst(gCofo *gc){
	if (gc != NULL){
		if (gc->numItens > 0){
			gc->cur = 0;
			return gc->item[gc->cur];
		}
	}
	return NULL;
}

void *gcofGetNext(gCofo *gc){
	if (gc != NULL){
		if (gc->numItens > 0 && gc->cur < gc->numItens){
			gc->cur++;
			return gc->item[gc->cur];
		}
	}
	return NULL;
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

void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *a, void *b)){
	int stat, i;
	if (gc != NULL){
		if (gc->numItens > 0){
			for (i = 0; i < gc->numItens; i++){
				stat = cmp(gc->item[i], key);
				if (stat == TRUE){
					return gc->item[i];
				}
			}
		}
	}
	return NULL;
}

void *gcofRemove(gCofo *gc, void* key, int(*cmp)(void *a, void *b)){
	int stat, i, j;
	if (gc != NULL){
		if (gc->numItens > 0){
			for (i = 0; i < gc->numItens; i++){
				stat = cmp(gc->item[i], key);
				if (stat == TRUE){
					for (j = i; j < gc->numItens; j++){
						gc->item[j] = gc->item[j+1];
					}
					gc->numItens--;
					return gc->item[i];
				}
			}
		}
	}
	return NULL;
}

int esvaziaCofo(gCofo *gc){
	int i, j;
	Aluno *a;	
	if (gc != NULL){
		if (gc->numItens > 0){
			for (i = 0; i < gc->numItens; i++){
				for (j = i; j < gc->numItens; j++){
					gc->item[j] = gc->item[j+1];
				}
				gc->numItens--;
			}
			return TRUE;
		}
	}
	return FALSE;
}

int isEmpty(gCofo *gc){
	if (gc != NULL)
		return gc->numItens <= 0;
}
