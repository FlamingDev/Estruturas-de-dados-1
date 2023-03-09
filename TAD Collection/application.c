#include <stdio.h>
#include "cofo.c"
#define TRUE 1
#define FALSE 0

void MostraElmCofo(Cofo *c){
	int i;
	printf("[");
	for (i = 0; i < c->numItems; i++){
		printf(" %d ",c->item[i]);
	}
	printf("]\n");
}

int main(){
	int i,j;
	int opc, maxItens, criado = FALSE, aux, vazio = TRUE; 
	Cofo *c;
	do{
		printf("----------------------------------\n");
		printf("[1] Criar o cofo\n");
		printf("[2] Inserir elementos no cofo\n");
		printf("[3] Mostrar elementos do cofo\n");
		printf("[4] Consultar um dos elementos do cofo\n");
		printf("[5] Remover um elemento do cofo\n");
		printf("[6] Destruir o cofo\n");
		printf("[7] Encerrar o programa\n");		
		printf("----------------------------------\n");
		printf("Escolha sua opcao: ");
		scanf("%d",&opc);	
		switch(opc){
			case 1:
				if (!criado){ // se o cofo ainda não foi criado
					printf("Qual deve ser a capacidade maxima do cofo? ");
					scanf("%d",&maxItens);
					c = cofCreate(maxItens);
					if (c != NULL){
						printf("Cofo de %d elementos criado com sucesso\n");
						criado = TRUE;
					}
					else
						printf("ERRO ao criar o cofo\n");
				}
				else{
					printf("ERRO: Cofo ja criado\n");
				}
				break;
			case 2:
				if (criado){ // se o cofo já tiver sido criado
					int qtd, item;
					printf("Inserir quantos elementos no cofo? ");
					scanf("%d",&qtd);
					for (i = 0; i < qtd; i++){
						printf("Elemento %d: ",i);
						scanf("%d",&item);
						aux = cofInsert(c, item);
					}
					if (aux){
						printf("Sucesso ao inserir os itens\n");
						vazio = FALSE;
						break;
					}
					else{
						printf("ERRO ao inserir\n");
						break;
					}
				}
				printf("ERRO: Cofo nao criado\n");
				break;
			
			case 3:
				if (criado && !vazio)
					MostraElmCofo(c);
				else if (vazio)
					printf("ERRO: Cofo esta vazio\n");
				else
					printf("ERRO: Cofo nao criado\n");				
				break;
			
			case 4:
				if (criado && !vazio){
					int procurado;
					printf("Quem vc deseja procurar dentro do cofo?");
					scanf("%d",&procurado);
					aux = cofQuery(c,procurado);
					if (aux != FALSE){
						printf("Achamos o abelardo na posicao %d do cofo\n",aux);
					}
					else{
						printf("ERRO: Abelardo nao encontrado no cofo\n");
					}
				}
				else if (vazio){
					printf("ERRO: Cofo esta vazio\n");
				}
				else{
					printf("ERRO: Cofo nao criado\n");
				}				
				break;
			
			case 5:
				if (criado && !vazio){
					int item;
					printf("Deseja remover qual elemento? ");
					scanf("%d",&item);
					aux = cofRemove(c,item);
					if (aux != FALSE){
						printf("Item removido com sucesso\n");
					}
					else{
						printf("ERRO: Item a ser removido nao existe no cofo\n");
					}
				}
				else if (vazio){
					printf("ERRO: Cofo esta vazio");
				}
				else{
					printf("ERRO: Cofo nao criado");
				}				
				break;
			
			case 6:
				if (criado && c->numItems == 0){
					cofDestroy(c);
					criado = FALSE;
					printf("Cofo destruido com sucesso\n");
				}
				else if (!vazio){
					printf("ERRO: Cofo nao esta vazio\n");				
				}
				else{
					printf("ERRO: Cofo nao criado\n");
				}
				break;
		}
	}while (opc != 7);
		
	return 0;
}
