#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

//FUNÇÕES///////////

//Insere um produto na pilha
void push(Produto prod, Pilha *p){
Node *ptr = (Node*) malloc(sizeof(Node));
if  (ptr==NULL){
    printf("Erro ao alocar nó\n");
}
else{
    ptr->produto.codigo=prod.codigo;
    strcpy(ptr->produto.nome, prod.nome);
    ptr->produto.quantidade=prod.quantidade;
    ptr->proximo=p->topo;
    p->topo = ptr;
    printf("Item Empilhado\n");
}
}

//Inicializa uma pilha
void InicializarPilha (Pilha *p){
p->topo=NULL;
printf("Pilha inicializada\n\n");
}

//Desempilha o item no topo da lista e o mostra
void pop(Pilha *p) {
Node* ptr = p->topo;
Produto d;
if(ptr == NULL){
    printf("Pilha vazia\n");

}
else {
    p->topo = ptr->proximo;
    ptr->proximo = NULL;
    d = ptr->produto;
    printf("Produto desempilhado:\n");
    printf("\nNome: %s", d.nome);
    printf("Codigo: %d\n", d.codigo);
    printf("Quantidade: %d\n", d.quantidade);
    printf("*************************\n");
    free(ptr);
}
}

//Imprime a pilha e mostra a quantidade de itens
void Imprime(Pilha *p) {
int t=0;
Node *ptr = p->topo;
if (ptr == NULL){
    printf("Pilha Vazia\n");
}
else {
    while (ptr != NULL){
        printf("\nNome: %s", ptr->produto.nome);
        printf("Codigo: %d\n", ptr->produto.codigo);
        printf("Quantidade: %d\n", ptr->produto.quantidade);
        printf("*************************\n");
        t++;
        ptr = ptr->proximo;
    }
    printf("TOTAL DE PRODUTOS: %d\n", t);
    printf("*************************\n");
}
}

//Cria um novo produto
Produto InsereProduto(){
Produto prod;
int cod, qtd;
printf("\nEntre com o nome: ");
fgets(prod.nome,50,stdin);
getchar();
printf("\nEntre com o codigo: ");
scanf("%d", &cod);
printf("\nEntre com a quantidade: ");
scanf("%d", &qtd);
prod.codigo=cod;
prod.quantidade=qtd;
return prod;
}

//Verifica se a pilha está vazia
int isEmpty(Pilha *p){
Node* ptr = p->topo;
if(ptr == NULL){
    printf("Pilha vazia: ");
    return 0;
}
else {
    printf("Pilha contem elemento(s): ");
    return 1;
}
}

//Exibe o produto no topo da pilha sem removê-lo
void topo(Pilha *p){
Node *ptr = p->topo;
if (ptr == NULL){
    printf("Pilha Vazia\n");
}
else {
    printf("Produto no topo da lista:\n");
    printf("\nNome: %s", ptr->produto.nome);
    printf("Codigo: %d\n", ptr->produto.codigo);
    printf("Quantidade: %d\n", ptr->produto.quantidade);
    printf("*************************\n");
}
}



//MAIN///////////////

int main(){

int opcao, v;
Produto prod;
Pilha *p =  (Pilha*) malloc(sizeof(Pilha));
if (p==NULL){
    printf("ERROR\n");
}

do {

printf("\n1- Inicializar pilha\n");
printf("2- Empilhar novo produto\n");
printf("3- Desempilhar produto\n");
printf("4- Consultar pilha vazia\n");
printf("5- Imprimir Pilha de produtos\n");
printf("6- Consultar Produto no topo da pilha\n");
printf("7- Sair\n");
scanf("%d",&opcao);
getchar();

switch(opcao)
{
case 1:{
InicializarPilha(p);
break;
}

case 2: {
prod = InsereProduto();
push(prod, p);
break;
}

case 3: {
pop(p);
break;
}

case 4: {
v=isEmpty(p);
printf("%d\n", v);
break;
}

case 5: {
Imprime(p);
break;
}

case 6:{
topo(p);
break;
}
}
}while(opcao!=7);


return 0;
}
