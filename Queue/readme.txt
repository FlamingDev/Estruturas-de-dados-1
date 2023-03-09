- Coleção onde a inserção é feita numa extremidade e a remoção na outra (FIFO)
- front guarda o índice do primeiro elemento da fila
- rear guarda o indice do ultimo elemento da fila
- inserir incrementa o rear e armazena o elemento em item[q->rear]
- remover decrementa o rear
- muito usado quando existe um recurso e muitas pessoas querendo acessar
struct queue{
	int front, rear;  
	int maxItens;
	void **item; 
};