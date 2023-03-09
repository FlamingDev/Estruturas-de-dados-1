#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#include "pilha.h"

struct stack{
	int maxItens;
	int top;
	void **item;
};

Stack *stkCreate(int maxItens){
	Stack *s;
	if (maxItens > 0){
		s = (Stack *) malloc(sizeof(Stack));
		if (s != NULL){
			s->item = (void **) malloc(maxItens*sizeof(void*));
			if (s->item != NULL){
				s->maxItens = maxItens;
				s->top = -1;
				return s;
			}
			free(s->item);
		}
		free(s);
	}
	return NULL;	
}

int stkDestroy(Stack *s){
	if (s != NULL){
		if (s->top < 0){
			free(s->item);
			free(s);
			return TRUE;
		}
	}
	return FALSE;
}

int stkPush(Stack *s, void *elm){
	if (s != NULL){
		if (s->top < s->maxItens-1){
			s->top++;
			s->item[s->top] = elm;
			return TRUE;
		}
	}
	return FALSE;
}

void *stkPop(Stack *s){
	void *elm;
	if (s != NULL){
		if (s->maxItens >= 0){
			elm = s->item[s->top];
			s->top--;
			return elm;
		}	
	}
	return NULL;
}

void *stkTop(Stack *s){
	if (s != NULL){
		if (s->top >= 0){
			void *elm = s->item[s->top];
			return elm;
		}
	}
	return NULL;
}

int stkIsEmpty(Stack *s){
	if (s != NULL){
		if (s->top < 0){
			return TRUE;
		}
	}
	return FALSE;
}

void limpaPilha(Stack *s){
	int i;
	if (s != NULL){
		if (s->top >= 0){
			while (!stkIsEmpty(s)){
				stkPop(s);
			}
		}
	}
}

void stkDestroyAny(Stack *s){
	void *elm = stkPop(s);
	if (s != NULL){
		while (elm != NULL){
			elm = stkPop(s);
		}
		free(s->item);
		free(s);
	}
}

// funções alternativas que o professor Anselmo passou como exercício

int EhPalindromo(char *str, int n){ // uso da pilha para verificar se uma string é palíndromo ou não
	Stack *s;
	char *aux;
	int i;
	if (str != NULL){
		s = stkCreate(n);
		for (i = 0; i < n; i++){
			stkPush(s,(void*)&str[i]);
		}
		for (i = 0; i < n; i++){
			aux = stkPop(s);
			if (*aux != str[i]){
				return FALSE;
			}
		}
		return TRUE;
	}
	return -1;	
}

int EhX0Y(char *str, int n){ // verifica se uma string está no formato x0y, onde x é o inverso de y
	Stack *s;
	char *aux;
	int i = 0, j;
	if (str != NULL){
		s = stkCreate(n);
		if (s != NULL){
			while (str[i] != '0'){
				stkPush(s,(void*)&str[i]);
				i++;
				if (str[i] == '\0'){
					return FALSE;
				}
			}
			for (j = i+1; j < n; j++){
				aux = stkPop(s);
				if (*aux != str[j]){
					return FALSE;
				}
			}
			return TRUE;
		}
	}
	return -1;
}

int stkPromoveUltimo(Stack *s, int n){ // promove o último da pilha em n posições
	void *data;
	int i,j, moves;
	if (s != NULL){
		if (s->top > 0){
			data = s->item[0];
			if (n < s->top){
				moves = n;
			}
			else{
				moves = s->top;
			}
			j = 0;
			for (i = moves; i > 0; i--){
				s->item[j] = s->item[j+1];
				j++;
			}
			s->item[j] = data;
			return TRUE;
		}
	}
	return FALSE;
}

int stkPunePrimeiro(Stack *s, int n){ // pune o topo da pilha em n posições
	void *data;
	int i,j, moves;
	if (s != NULL){
		if (s->top > 0){
			data = s->item[s->top];
			if (n < s->top){
				moves = n;
			}
			else{
				moves = s->top;
			}
			j = s->top;
			for (i = moves; i > 0; i--){
				s->item[j] = s->item[j-1];
				j--;
			}
			s->item[j] = data;
			return TRUE;
		}
	}
	return FALSE;
}

int stkRemove(Stack *s, int key){ // remove todos os elementos da pilha até que seja encontrado um elemento maior que key
	int i,j,k = 0;
	if (s != NULL && key >= 0){
		if (s->top >= 0){
			for (i = 0; i <= s->top; i++){
				for (j = s->top; j >= key; j--){
					s->item[j] = s->item[j+1];	
				}			
			}
			return TRUE;
		}
	}
	return FALSE;
}
