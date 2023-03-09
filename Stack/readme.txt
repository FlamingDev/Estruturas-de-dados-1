- Início das restrições de acesso
- Last in First out
- Operações afetam somente o elemento mais recente
- Criar, push, pop, destruir, Top, isEmpty
- top armazena a posição do ultimo elemento da pilha
- Push incrementa top e coloca o novo dado em s->itens[s->top]
- Pop retorna o itens[top] e decrementa top
- struct stack{
	int maxItens;
	int top; 
	void **itens;
};