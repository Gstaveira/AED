#include <stdio.h>
#include <stdlib.h>
#define MAXTAM  10

typedef int TipoApontador;

typedef struct {
 float valor;
 int prioridade;
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
} TipoFila;

void Inicializar(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(TipoItem x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila);
void Imprime(TipoFila Fila);
TipoItem InsereItem();
