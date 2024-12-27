#include <stdio.h>
#define max 10

//Função que implementa o Insertion Sort

int main(){

void InsertionSort(int vetor[max], int tamanho){

int i, j, k, chave;
for(i=1; i<tamanho; i++){
    chave = vetor[i];

    for(j=1-i;(j>=0 && vetor[j]>chave); j--){
        vetor[j+1]=vetor[j];
    }

vetor[j+1]=chave;
}
printf("Vetor ordenado\n");
for (k=0; k<tamanho; k++){
    printf("%d\n", vetor[i]);
}

}

int vetor[max];
int tam, i;

printf("Insira o tamanho do vetor: ");
scanf("%d", &tam);


for(i=0; i<tam; i++){
    printf("Entre com o valor da posicao %d: ", i+1);
    scanf("%d", &vetor[i]);
}

InsertionSort(&vetor[max], tam);

return 0;
}
