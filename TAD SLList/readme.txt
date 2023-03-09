- Listas, diferente das outras EDs possui elementos não contiguos pois não estão mais em um vetor
- Analogia: cada carangueijo mora numa casa diferente e num bairro diferente, carangueijos e Ser supremo que sabe onde mora o primeiro carangueijo.
  Cada carangueijo tem um papel dizendo onde fica o próximo carangueijo, e o último elemento da lista sempre tem um papel em branco (NULL)
- Em uma estrutura de dados encadeada alocação de memória é sob demanda
- cada elemento da lista possui um ponteiro para o próximo
- cada item (tipo node) é uma caixa de sapato com um papel dizendo onde o elemento mora e outro papel dizendo onde tá a próxima caixa
- SLList (ser supremo) e SLnode(caixad de sapato com ponteiro para void e ponteiro pro próximo)
- A lista está vazia quando o campo first do SLList é igual a NULL
- struct slnode{
	void *data;
	struct slnode *next;
};

struct sllist{
	struct slnode *first;
};