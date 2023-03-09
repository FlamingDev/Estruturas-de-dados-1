#include <stdio.h>
#include <stdlib.h>
#include "gCofo.c"
#define TRUE 1
#define FALSE 0

void MostraAlunosCofo(gCofo *gc){
	int i;
	Aluno *a = gcofGetFirst(gc);
	printf("[");
	for (i = 0; i < gc->numItens; i++){
		printf("\nNome: %s\nNota: %f\nID: %d\n",a->nome,a->nota,a->id);
		a = gcofGetNext(gc);
	}
	printf("]\n");
}

int main(){
	int i,j;
	char nome[30];
	float nota;
	int ID;
	Aluno *a;
	int opc, maxItens, criado = FALSE, aux = FALSE; 
	gCofo *gc = NULL; 
	
	do{
		criado = gc != NULL;
		printf("----------------------------------\n");
		printf("[1] Criar o cofo\n");
		printf("[2] Inserir alunos no cofo\n");
		printf("[3] Mostrar alunos do cofo\n");
		printf("[4] Consultar um dos alunos do cofo\n");
		printf("[5] Remover um aluno do cofo\n");
		printf("[6] Esvaziar cofo\n");
		printf("[7] Destruir o cofo\n");
		printf("[8] Encerrar o programa\n");		
		printf("----------------------------------\n");
		printf("Escolha sua opcao: ");
		scanf("%d",&opc);	
		switch(opc){
			case 1:
				if (!criado){ 
					printf("Qual deve ser a capacidade maxima do cofo? ");
					scanf("%d",&maxItens);
					gc = gcofCreate(maxItens);
					if (gc != NULL){
						printf("Cofo de %d alunos criado com sucesso\n",maxItens);
					}
					else
						printf("ERRO ao criar o cofo\n");
				}
				else{
					printf("ERRO: Cofo ja criado\n");
				}
				break;
			case 2:
				if (criado){					
					int qtd;
					printf("Inserir quantos alunos no cofo? ");
					scanf("%d",&qtd);
					for (i = 0; i < qtd; i++){
						a = (Aluno *) malloc(sizeof(Aluno));
						printf("Nome do %do aluno: ",i+1);					
						scanf("%s",&a->nome);
						printf("Nota do %do aluno: ",i+1);
						scanf("%f",&a->nota);
						printf("ID do %do aluno: ",i+1);
						scanf("%d",&a->id);
						aux = gcofInsert(gc, a);
					}
					if (aux){
						printf("Sucesso ao inserir os itens\n");
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
				if (criado && !isEmpty(gc))
					MostraAlunosCofo(gc);
				else if (isEmpty(gc))
					printf("ERRO: Cofo esta vazio\n");
				else
					printf("ERRO: Cofo nao criado\n");				
				break;
				
			case 4:
				if (criado && !isEmpty(gc)){
					int opc_query;
					printf("Buscar por:\n[0]Nome\n[1]Nota\n[2]ID\nSua opcao:");
					scanf("%d",&opc_query);
					if (opc_query == 0){
						printf("Nome do aluno: ");
						scanf("%s",&nome);
						a = gcofQuery(gc,(void*)nome,QueryAlunoNome);
					}
					else if (opc_query == 1){
						printf("Nota do aluno: ");
						scanf("%f",&nota);
						a = gcofQuery(gc,(void*)&nota,QueryAlunoNota);
					}
					else if (opc_query == 2){
						printf("ID do aluno: ");
						scanf("%d",&ID);
						a = gcofQuery(gc,(void*)&ID,QueryAlunoID);
					}
					
					if (a != NULL){
						printf("Aluno de nome %s, nota %f e ID %d encontrado no cofo\n",a->nome,a->nota,a->id);
					}
					else{
						printf("ERRO: Aluno nao encontrado\n");
					}		
				}
				else if (isEmpty(gc)){
					printf("ERRO: Cofo esta vazio\n");
				}
				else{
					printf("ERRO: Cofo nao criado\n");
				}				
				break;
								
			case 5:
				if (criado && !isEmpty(gc)){
					int opc_remove;					
					printf("Remover por:\n[0]Nome\n[1]Nota\n[2]ID\nSua opcao:");
					scanf("%d",&opc_remove);
					if (opc_remove == 0){
						fflush(stdin);
						printf("Nome do aluno: ");
						gets(nome);
						a = gcofRemove(gc,(void*)nome,QueryAlunoNome);
					}
					else if (opc_remove == 1){
						printf("Nota do aluno: ");
						scanf("%f",&nota);
						a = gcofRemove(gc,(void*)&nota,QueryAlunoNota);
					}
					else if (opc_remove == 2){
						printf("ID do aluno: ");
						scanf("%d",&ID);
						a = gcofRemove(gc,(void*)&ID,QueryAlunoID);
					}
					if (a != NULL){
						printf("Aluno removido com sucesso\n");
					}
					else{
						printf("ERRO: Aluno a removido nao existe no cofo\n");
					}
				}
				else if (isEmpty(gc)){
					printf("ERRO: Cofo esta vazio\n");
				}
				else{
					printf("ERRO: Cofo nao criado\n");
				}				
				break;
				
			case 6:
				if (criado && !isEmpty(gc)){
					aux = esvaziaCofo(gc);
					if (aux){
						printf("Cofo esvaziado com sucesso\n");
					}
					else{
						printf("ERRO ao esvaziar o cofo\n");
					}
					break;
				}
				else if (isEmpty(gc)){
					printf("ERRO: Cofo esta vazio\n");
				}
				else{
					printf("ERRO: Cofo nao criado\n");
				}
				break;
				
			case 7:
				if (criado && isEmpty(gc)){
					gcofDestroy(gc);
					gc = NULL;
					printf("Cofo destruido com sucesso\n");
				}
				else if (!isEmpty(gc)){
					printf("ERRO: Cofo nao esta vazio\n");				
				}
				else{
					printf("ERRO: Cofo nao criado\n");
				}
				break;
			
		}
	}while (opc != 8);
		
	return 0;
	}
