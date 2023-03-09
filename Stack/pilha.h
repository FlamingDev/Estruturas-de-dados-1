typedef struct stack Stack;
Stack *stkCreate(int maxItens); // cria uma pilha vazia 
int stkPush(Stack *s, void *elm); // bota o elemento na pilha e retorna True ou False
void *stkPop(Stack *s); // Decrementa a pilha e retorna o elemento desempilhado
void *stkTop(Stack *s); // faz a mesma coisa da Pop mas não retira o elemento da pilha
int stkIsEmpty(Stack *s); // verifica se a pilha está vazia ou nao, retorna True ou FALSE
void stkLimpaPilha(Stack *s); // esvazia a pilha
int stkDestroy(Stack *s); // destroi a pilha
void stkDestroyAny(Stack *s); // destrói qualquer pilha, mesmo se não estiver vazia
