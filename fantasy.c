#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "trab.h"

//Cria um sistema de Fantasy Game da Fórmula 1

//GABRIEL SILVA TAVEIRA 201800085

// inserir no final da lista
void inserir(Lista *lista, PILOTOS p) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    strcpy(novo->pilot.nome, p.nome);
    novo->pilot.num = p.num;
    novo->pilot.idade = p.idade;
    strcpy(novo->pilot.equipe, p.equipe);
    novo->pilot.valor = p.valor;
    novo->pilot.pont = p.pont;
    novo->proximo = NULL;

    if(lista->inicio == NULL) { // lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    printf("\nPiloto Inserido\n");
    lista->tam++;
}

// remover um elemento da lista
void remover(Lista *lista, int valor) {
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No * Remover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->pilot.num == valor) { // remover 1º elemento
        Remover = lista->inicio;
        lista->inicio = Remover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->pilot.num != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            Remover = inicio->proximo;
            inicio->proximo = Remover->proximo;
            if(inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if(Remover) {
        free(Remover); // libera a memória do nó
        lista->tam--; // decrementa o tamanho da lista
        printf("Piloto Removido!\n");
    } else {
        printf("Piloto nao encontrado\n");
        }

}

// imprimir a lista
void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
        printf("\n********************\n");
    while(inicio != NULL) {
        printf("Nome: %s", inicio->pilot.nome);
        printf("Numero: %d\n", inicio->pilot.num);
        printf("Idade: %d\n", inicio->pilot.idade);
        printf("Equipe: %s", inicio->pilot.equipe);
        printf("Pontuacao: %d\n", inicio->pilot.pont);
        printf("Valor: $%.2f\n", inicio->pilot.valor);
        printf("********************\n");
        inicio = inicio->proximo;
    }
    printf("Total de pilotos: %d\n", lista->tam);
}

//Selection Sort
void selectsort(Lista *lista) {
    No *i, *j, *aux;
    aux = (No*)malloc(sizeof(No));
    i = lista->inicio;
    while( i != NULL) {
        j = i->proximo;
        while (j != NULL) {
            if (i->pilot.num > j->pilot.num){
                //  swap dos ponteiros
                *aux = *i ; // copia valor de i em aux.
                *i =  *j; // copia valor de j em i.
                i->proximo = aux->proximo; // altera ponterio do próximo de i para que ele continue sendo o mesmo que era antes da copia
                aux->proximo = j->proximo; // copia o valor do ponteiro do proximo j
                *j = *aux; // copia valor de aux em j.
                j->proximo = aux->proximo; // altera ponterio do próximo de i para que ele continue sendo o mesmo que era antes da copia
                }
            j = j->proximo;
        }
    i = i->proximo;
    }
}

//Busca Sequencial
void buscaSeq(int n, Lista *lista){
    int l=0;
    No *inicio = lista->inicio;
    while(l==0 && inicio != NULL){
        if(inicio->pilot.num == n){
            l++;
        }
        else{
            inicio = inicio->proximo;
            }
        }
        if(l == 0){
            printf("\nPiloto nao encontrado\n");
        }
        else {
            printf("\n***Resultado da Busca Sequencial***\n");
            printf("Nome: %s", inicio->pilot.nome);
            printf("Numero: %d\n", inicio->pilot.num);
            printf("Idade: %d\n", inicio->pilot.idade);
            printf("Equipe: %s", inicio->pilot.equipe);
            printf("Pontuacao: %d\n", inicio->pilot.pont);
            printf("Valor: $%.2f\n", inicio->pilot.valor);
            printf("***Fim da Busca***\n");
        }
}

//Busca Binaria
void buscaBin(int n, Lista *lista){
int meio, in=0, fim, l=0, i;
No *inicio = lista->inicio;
fim=(lista->tam)-1;
while(in <= fim && l==0){
    meio = (in + fim) / 2;
    inicio = lista->inicio;
    for (i=0; i<meio; i++){
        inicio = inicio->proximo;
    }
    if (inicio->pilot.num == n){
        printf("\n***Resultado da Busca Binaria***\n");
        printf("Nome: %s", inicio->pilot.nome);
        printf("Numero: %d\n", inicio->pilot.num);
        printf("Idade: %d\n", inicio->pilot.idade);
        printf("Equipe: %s", inicio->pilot.equipe);
        printf("Pontuacao: %d\n", inicio->pilot.pont);
        printf("Valor: $%.2f\n", inicio->pilot.valor);
        printf("***Fim da Busca***\n");
        l++;
    }
    else if(n < inicio->pilot.num){
        fim = meio-1;
    }
    else {
        in = meio+1;
    }
}
if(l == 0){
    printf("\nPiloto nao encontrado\n");
}
}

//Imprime a equipe
void imprimirEquipe (EQUIPE e, int n){
int i;
for(i=0; i<n; i++){
    printf("Nome: %s\n", e.equipe[i].nome);
    printf("Numero: %d\n", e.equipe[i].num);
    printf("Idade: %d\n", e.equipe[i].idade);
    printf("Equipe: %s\n", e.equipe[i].equipe);
    printf("Pontuacao: %d\n", e.equipe[i].pont);
    printf("Valor: $%.2f\n", e.equipe[i].valor);
    printf("********************\n");
}
}

//Inserir Piloto na equipe
int inserirEquipe(EQUIPE *e, Lista *lista, int cont){
    int i, j=0, l=0, n, ncont;
    float saldo;
    No *inicio = lista->inicio;

    printf("Insira o numero do piloto: ");
    scanf("%d", &n);

    if (cont>=5){
        printf("\nA equipe esta cheia, remova pelo menos um piloto\n");
        return cont;
    }

    else {
        for(i=0; i<cont; i++){
            if(e->equipe[i].num==n){
                j++;
            }
        }
        if(j>0){
            printf("O piloto escolhido ja faz parte da equipe, escolha outro\n");
            return cont;
        }

        while(l==0 && inicio != NULL){
            if(inicio->pilot.num == n){
                l++;
            }
            else{
                inicio = inicio->proximo;
            }
        }
        if(l == 0){
            printf("Piloto nao encontrado\n");
            return cont;
        }

        saldo= valorEquipe(*e, cont);
        if (saldo+inicio->pilot.valor>100.00){
        printf("Saldo insuficiente para adicionar piloto\n");
        return cont;
        }
        else {
                strcpy(e->equipe[cont].nome, inicio->pilot.nome);
                strcpy(e->equipe[cont].equipe, inicio->pilot.equipe);
                e->equipe[cont].num=inicio->pilot.num;
                e->equipe[cont].idade=inicio->pilot.idade;
                e->equipe[cont].pont=inicio->pilot.pont;
                e->equipe[cont].valor=inicio->pilot.valor;
                printf("Piloto adicionado com sucesso\n");
                ncont=cont+1;
        }
    }
}

//Remover um piloto da equipe
int removerPiloto(EQUIPE *equipe, int cont) {
    int num_piloto, i;
    int indice = -1;
    int ncont;
    do{
        printf("Insira o numero do piloto: ");
        scanf("%d", &num_piloto);

        for (i = 0; i < cont; i++) {
            if (equipe->equipe[i].num == num_piloto) {
            indice = i;
            break;
            }
        }

        if (indice == -1) {
        printf("Piloto com o numero %d nao encontrado na equipe.\n", num_piloto);
        }

    } while (indice==-1);

    for (int i = indice; i < cont - 1; i++) {
        equipe->equipe[i] = equipe->equipe[i + 1];
    }
    ncont=cont-1;
    return ncont;
}

//Receber o valor total da equipe
float valorEquipe(EQUIPE e, int cont){
    float saldo=0;
    int i;
    for (i=0; i<cont; i++){
        saldo=saldo+e.equipe[i].valor;
    }
    return saldo;
}

//SelectionSort
void selectionsort(PILOTOS equipe[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (equipe[j].pont < equipe[min].pont) {
                min = j;
            }
        }
        if (min != i) {
            trocar(&equipe[i], &equipe[min]);
        }
    }
}

//trocar vetores de posicao
void trocar(PILOTOS *a, PILOTOS *b) {
    PILOTOS temp = *a;
    *a = *b;
    *b = temp;
}

//particionar vetores
int particionar(PILOTOS equipe[], int esquerda, int direita) {
    int pivo = equipe[direita].pont;
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; j++) {
        if (equipe[j].pont <= pivo) {
            i++;
            trocar(&equipe[i], &equipe[j]);
        }
    }

    trocar(&equipe[i + 1], &equipe[direita]);
    return i + 1;
}

//Quicksort
void quicksort(PILOTOS equipe[], int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = particionar(equipe, esquerda, direita);
        quicksort(equipe, esquerda, pivo - 1);
        quicksort(equipe, pivo + 1, direita);
    }
}

//Shellsort
void shellsort(PILOTOS equipe[], int n) {
    int intervalo, i, j;
    PILOTOS temp;

    for (intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < n; i++) {
            temp = equipe[i];
            for (j = i; j >= intervalo && equipe[j - intervalo].pont > temp.pont; j -= intervalo) {
                equipe[j] = equipe[j - intervalo];
            }
            equipe[j] = temp;
        }
    }
}

//Obter tempo de execucao
long long obtertempo() {
    struct timespec tempo;
    clock_gettime(CLOCK_MONOTONIC, &tempo);
    return tempo.tv_sec * 1000000000LL + tempo.tv_nsec;
}


int main(){


    int opcao, nu, i, np, op, k;
    Lista lispilot;
    PILOTOS pi;

    // inicialização da lista
    lispilot.inicio = NULL;
    lispilot.fim = NULL;
    lispilot.tam = 0;

    do {

        printf("\n1- Inserir Piloto\n");
        printf("2- Remover Piloto\n");
        printf("3- Lista de Pilotos Inseridos\n");
        printf("4- Ordenar Lista de Pilotos\n");
        printf("5- Concluir Insercao de Pilotos e criar sua equipe\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao)
        {

            case 1:{
                printf("\nEntre com o nome do piloto: ");
                fgets(pi.nome,40,stdin);
                getchar();
                printf("\nEntre com o numero do piloto: ");
                scanf("%d", &pi.num);
                getchar();
                printf("\nEntre com a idade do piloto: ");
                scanf("%d", &pi.idade);
                getchar();
                printf("\nEntre com o nome da equipe do piloto: ");
                fgets(pi.equipe,40,stdin);
                getchar();
                printf("\nEntre com o valor do piloto: ");
                scanf("%f", &pi.valor);
                getchar();
                printf("\nEntre com a pontuacao do piloto: ");
                scanf("%d", &pi.pont);
                getchar();
                long long inicio = obtertempo();
                inserir(&lispilot, pi);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO DE INSERCAO DA LISTA: %.9f SEGUNDOS\n", tempo_execucao);
                break;
            }

            case 2: {
                printf("Insira o numero do piloto: ");
                scanf("%d", &nu);
                long long inicio = obtertempo();
                remover(&lispilot, nu);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO DE REMOCAO DA LISTA: %.9f SEGUNDOS\n", tempo_execucao);
                break;
            }

            case 3: {
                long long inicio = obtertempo();
                imprimir(&lispilot);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO DE IMPRESSAO DA LISTA: %.9f SEGUNDOS\n", tempo_execucao);
            break;
            }

            case 4: {
                long long inicio = obtertempo();
                selectsort(&lispilot);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO DE IMPRESSAO DA LISTA: %.9f SEGUNDOS\n", tempo_execucao);
                printf("\n Lista ordenada por Selection Sort\n");
                imprimir(&lispilot);
            break;
            }

        }
    }while(opcao!=5);

    char nome[40];
    float bud;
    int pontos=0, cont=5;
    printf("\nEntre Com o Nome da Equipe: ");
    fgets(nome,40,stdin);
    printf("Equipe criada!\n");
    EQUIPE equipe1 = {
            {{"Max", 33, 24.5, "RB", 25, 25},
             {"Norris", 4, 14.5, "Mclaren", 28, 20},
             {"Albon", 23, 8.7, "Williams", 27, 10},
             {"Bottas", 77, 7.0, "Alfa Romeo", 34, 15},
             {"Alonso", 14, 14.6, "Aston Martin", 42, 30}}
    };
    int tamanho_equipe = sizeof(equipe1.equipe) / sizeof(equipe1.equipe[0]);

    do {

        printf("\n1- Inserir Piloto na Equipe\n");
        printf("2- Remover Piloto da Equipe\n");
        printf("3- Pesquisar Piloto na Lista\n");
        printf("4- Informacoes da Equipe\n");
        printf("5- Ordenar Equipe\n");
        printf("0- Sair\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao)
        {
            case 1: {
                cont = inserirEquipe(&equipe1, &lispilot, cont);

            break;
            }

            case 2: {
                cont = removerPiloto(&equipe1, cont);

            break;
            }

            case 3: {
                printf("\nEntre Com o Numero do Piloto:");
                scanf("%d", &np);
                do {
                    printf("\nInsira 1 para busca sequencial ou 2 para busca binaria: ");
                    scanf("%d", &op);
                }while (op!=1 && op!=2);
                if (op==1){
                    long long inicio = obtertempo();
                    buscaSeq(np, &lispilot);
                    long long fim = obtertempo();
                    double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                    printf("TEMPO DE EXECUCAO DA BUSCA SEQUENCIAL: %.9f SEGUNDOS\n", tempo_execucao);
                }
                if (op==2){
                    long long inicio = obtertempo();
                    buscaBin(np, &lispilot);
                    long long fim = obtertempo();
                    double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                    printf("TEMPO DE EXECUCAO DA BUSCA BINARIA: %.9f SEGUNDOS\n", tempo_execucao);
                }
            break;
            }

            case 4: {
                printf("\n*****Equipe: %s", nome);
                printf("**Pilotos**\n");
                tamanho_equipe = sizeof(equipe1.equipe) / sizeof(equipe1.equipe[0]);
                imprimirEquipe (equipe1, cont);
                printf("Total de pilotos: %d\n", cont);
                for (i=0; i<cont; i++){
                    pontos=pontos+equipe1.equipe[i].pont;
                }
                bud = valorEquipe(equipe1, cont);
                printf("Saldo Restante: %.2f\n", 100.00 - bud);
                printf("Total de pilotos: %d\n", cont);
                printf("Pontuacao da equipe: %d\n", pontos);
                printf("********************\n");
                pontos=0;
            break;
            }

            case 5: {
                do {
                    printf("\nInsira 1 para utilizar Selection Sort, 2 para Shell Sort ou 3 para Quick Sort: ");
                    scanf("%d", &op);
                }while (op!=1 && op!=2 && op!=3);
                if (op==1){
                long long inicio = obtertempo();
                selectionsort(equipe1.equipe, cont);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO SELECTION SORT: %.9f SEGUNDOS\n", tempo_execucao);
                printf("\nLista ordenada por Selection Sort\n");

                imprimirEquipe (equipe1, cont);
                }
                if (op==2){
                long long inicio = obtertempo();
                shellsort(equipe1.equipe, cont);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO SHELLSORT: %.9f SEGUNDOS\n", tempo_execucao);
                printf("\nLista ordenada por Shell Sort\n");
                imprimirEquipe (equipe1, cont);
                }
                if (op==3){
                long long inicio = obtertempo();
                quicksort(equipe1.equipe, 0, cont - 1);
                long long fim = obtertempo();
                double tempo_execucao = (double)(fim - inicio) / 1000000000.0;
                printf("TEMPO DE EXECUCAO DA FUNCAO QUICKSORT: %.9f SEGUNDOS\n", tempo_execucao);
                printf("\nLista ordenada por Quick Sort\n");
                imprimirEquipe (equipe1, cont);
                }

            break;
            }
        }
    }while(opcao!=0);


return 0;
}
