// Estrutura de dados para representar um produto
typedef struct Produto
{
 int codigo;
 char nome[50];
 int quantidade;
}Produto;

// Estrutura de dados para representar um nó da pilha
typedef struct Node
{
 Produto produto;
 struct Node* proximo;
}Node;

// Estrutura de dados para representara pilha
typedef struct Pilha
{
 Node* topo;
}Pilha;

//Funções
void InicializarPilha (Pilha *p);
Produto InsereProduto();
void push(Produto prod, Pilha *p);
void pop(Pilha *p);
void Imprime(Pilha *p);
int isEmpty(Pilha *p);
void topo(Pilha *p);
