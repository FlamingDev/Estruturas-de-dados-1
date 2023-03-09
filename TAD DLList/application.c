#include <stdio.h>
#include <stdlib.h>
#include "Lista dupla.c"
#define TRUE 1
#define FALSE 0

/* Código feito por Breno Roberto Reis Vidigal */

void MostraAlunosLista(DLList *l){
	Aluno *a; int i;
	if (l != NULL){
		for (i = 0; i < dllNElms(l); i++){
			a = dllGet(l, i);
			printf("\nAluno %d: %s\nNota: %f\nID: %d\n",i,a->nome,a->nota,a->id);
		}
	}
}

int main(){

	DLList *l = NULL;
	int i,j;
	char nome[30];
	float nota;
	int ID;
	Aluno *a;
	int opc, aux; 
		
	do{
		criado = l != NULL;
		printf("----------------------------------\n");
		printf("[1] Criar a lista\n");
		printf("[2] Inserir alunos na lista\n");
		printf("[3] Mostrar alunos da lista\n");
		printf("[4] Consultar um dos alunos na lista\n");
		printf("[5] Remover um aluno da lista\n");
		printf("[6] Esvaziar a lista\n");
		printf("[7] Destruir a lista\n");
		printf("[8] Encerrar o programa\n");		
		printf("----------------------------------\n");
		printf("Escolha sua opcao: ");
		scanf("%d",&opc);
			
		switch(opc){
			case 1:
				if (!criado){
					l = dllCreate();
					if (l != NULL){
						printf("Lista duplamente encadeada criada com sucesso\n");
					}
					else
						printf("ERRO ao criar a lista\n");
				}
				else{
					printf("ERRO: Lista já criada\n");
				}
				break;
			case 2:
				if (criado){					
					int qtd;
					printf("Inserir quantos alunos na lista? ");
					scanf("%d",&qtd);
					for (i = 0; i < qtd; i++){
						a = (Aluno *) malloc(sizeof(Aluno));
						if (a != NULL){			
							printf("Nome do %do aluno: ",i+1);					
							scanf("%s",&a->nome);
							printf("Nota do %do aluno: ",i+1);
							scanf("%f",&a->nota);
							printf("ID do %do aluno: ",i+1);
							scanf("%d",&a->id);
							dllInsertAsLast(l,a);
						}						
					}
				}
				else{
					printf("ERRO: lista nao criada\n");
				}	
				break;
			
			case 3:
				if (criado && !isEmpty(l))
					MostraAlunosLista(l);
				else if (isEmpty(l))
					printf("ERRO: Lista esta vazia\n");
				else
					printf("ERRO: Lista nao criada\n");				
				break;
			
			case 4:
				if (criado && !isEmpty(l)){
					int opc_query;
					printf("Buscar por:\n[0]Nome\n[1]Nota\n[2]ID\nSua opcao:");
					scanf("%d",&opc_query);
					if (opc_query == 0){
						printf("Nome do aluno: ");
						scanf("%s",&nome);
						a =  dllQuery(l,nome,QueryAlunoNome);
					}
					else if (opc_query == 1){
						printf("Nota do aluno: ");
						scanf("%f",&nota);
						a = dllQuery(l,&nota,QueryAlunoNota);
					}
					else if (opc_query == 2){
						printf("ID do aluno: ");
						scanf("%d",&ID);
						a = dllQuery(l,&ID,QueryAlunoID);
					}
					
					if (a != NULL){
						printf("Aluno de nome %s, nota %f e ID %d encontrado na lista\n",a->nome,a->nota,a->id);
					}
					else{
						printf("ERRO: Aluno nao encontrado\n");
					}		
				}
				else if (isEmpty(l)){
					printf("ERRO: A lista esta vazia\n");
				}
				else{
					printf("ERRO: Lista nao criada\n");
				}				
				break;
				
			case 5:
				if (criado && !isEmpty(l)){
					int opc_remove;					
					printf("Remover por:\n[0]Nome\n[1]Nota\n[2]ID\nSua opcao:");
					scanf("%d",&opc_remove);
					if (opc_remove == 0){
						fflush(stdin);
						printf("Nome do aluno: ");
						gets(nome);
						a = dllRemoveSpec(l,(void*)nome,QueryAlunoNome);
					}
					else if (opc_remove == 1){
						printf("Nota do aluno: ");
						scanf("%f",&nota);
						a = dllRemoveSpec(l,(void*)&nota,QueryAlunoNota);
					}
					else if (opc_remove == 2){
						printf("ID do aluno: ");
						scanf("%d",&ID);
						a = dllRemoveSpec(l,(void*)&ID,QueryAlunoID);
					}
					if (a != NULL){
						printf("Aluno removido com sucesso\n");
					}
					else{
						printf("ERRO: Aluno a removido nao existe na lista\n");
					}
				}
				else if (isEmpty(l)){
					printf("ERRO: Lista esta vazia\n");
				}
				else{
					printf("ERRO: Lista nao criada\n");
				}				
				break;
				
			case 6:
				if (criado && !isEmpty(l)){
					dllRemoveAll(l);
					printf("Lista esvaziada com sucesso\n");
				}
				else if (isEmpty(l)){
					printf("ERRO: Lista esta vazia\n");
				}
				else{
					printf("ERRO: Lista nao criada\n");
				}		
				break;	
				
			case 7:
				if (criado && isEmpty(l)){
					dllDestroy(l);
					printf("Lista destruida com sucesso\n");
				}
				else if (!isEmpty(l)){
					printf("ERRO: Lista nao esta vazia\n");				
				}
				else{
					printf("ERRO: Lista nao criada\n");
				}
				break;
		}
	}while (opc != 8);
		
	return 0;
}
