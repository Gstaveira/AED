#include <stdio.h>
#include <stdlib.h>
#define MAXTAM  10
#include "ex3.h"

//Implementação de uma fila em C

void Inicializar(TipoFila *Fila)
{
  Fila->Frente = 0;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{
  return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
  if(Fila->Tras >= MAXTAM)
    printf("Erro! A fila esta cheia!\n");
  else
  {
    Fila->Item[Fila->Tras].prioridade=x.prioridade;
    Fila->Item[Fila->Tras].valor=x.valor;
    Fila->Tras=Fila->Tras+1;
    printf("Enfileirou: %.2f \n", x.valor);
    printf("Prioridade: %d \n", x.prioridade);

  }
}

void Desenfileira(TipoFila *Fila)
{
  if (Vazia(*Fila))
    printf("Erro! A fila esta vazia!\n");
  else
  {
    //int x = Fila->Item[Fila->Frente].Chave;
    Fila->Frente = Fila->Frente+1;
    //printf("Desenfileirou: %d\n", x);
  }
}

void Imprime(TipoFila Fila)
{
  int Aux;
  for (Aux = Fila.Frente; Aux <= (Fila.Tras - 1); Aux++)
    printf("Valor: %.2f\n", Fila.Item[Aux].valor);
    printf("Prioridade: %.2f\n", Fila.Item[Aux].prioridade);
}  /* Imprime */

TipoItem InsereItem(){
TipoItem item;
int prioridade;
float valor;
printf("\nEntre com o valor: ");
scanf("%f", &valor);
printf("\nEntre com a prioridade: ");
scanf("%d", &prioridade);
item.valor=valor;
item.prioridade=prioridade;
return item;
}


int main(){
TipoFila fila, fila2, fila3;
TipoItem item;
int i, j, p, n, Aux, valor;
Inicializar(&fila);

for (i = 0; i < 10; i++){
item=InsereItem();
Enfileira(item, &fila);
}

printf("\nInsira o valor p: ");
scanf("%d", &p);

Inicializar(&fila2);
Inicializar(&fila3);

for (Aux = fila.Frente; Aux <= (fila.Tras - 1); Aux++){
    if (fila.Item[Aux].prioridade<=p){
        item.prioridade=fila.Item[Aux].prioridade;
        item.valor=fila.Item[Aux].valor;
        Enfileira(item, &fila2);
    }
    else {
        item.prioridade=fila.Item[Aux].prioridade;
        item.valor=fila.Item[Aux].valor;
        Enfileira(item, &fila3);
    }
}
printf("Lista dos itens com prioridade menor ou igual a p:\n\n");
Imprime(fila2);
printf("Lista dos itens com prioridade maior que p:\n\n");
Imprime(fila3);
}

