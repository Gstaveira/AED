#include <stdio.h>
#include <stdlib.h>
#include "ex8.h"

void mergeSort(int arr[], int tam) {
    if (tam > 1) {
        int meio = tam / 2;
        int *esquerda = (int *)malloc(meio * sizeof(int));
        int *direita = (int *)malloc((tam - meio) * sizeof(int));

        for (int i = 0; i < meio; i++) {
            esquerda[i] = arr[i];
        }

        for (int i = meio; i < tam; i++) {
            direita[i - meio] = arr[i];
        }

        mergeSort(esquerda, meio);
        mergeSort(direita, tam - meio);
        particiona(arr, esquerda, meio, direita, tam - meio);

        free(esquerda);
        free(direita);
    }
}

void particiona(int arr[], int esq[], int tamEsq, int dir[], int tamDir) {
    int i = 0, j = 0, k = 0;

    while (i < tamEsq && j < tamDir) {
        if (esq[i] <= dir[j]) {
            arr[k++] = esq[i++];
        } else {
            arr[k++] = dir[j++];
        }
    }

    while (i < tamEsq) {
        arr[k++] = esq[i++];
    }

    while (j < tamDir) {
        arr[k++] = dir[j++];
    }
}



int main() {

    int arr1[] = {3, 7, 10, 20};
    int arr2[] = {2, 5, 8};
    int arr3[] = {1, 6, 9, 14};
    int tam1 = 4;
    int tam2 = 3;
    int tam3 = 4;
    int tamt = tam1+tam2+tam3;
    int particionar[tamt];
    int indice = 0;

    for (int i = 0; i < tam1; i++) {
        particionar[indice++] = arr1[i];
    }
    for (int i = 0; i < tam2; i++) {
        particionar[indice++] = arr2[i];
    }
    for (int i = 0; i < tam3; i++) {
        particionar[indice++] = arr3[i];
    }

    mergeSort(particionar, tamt);

    printf("Vetor ordenado e intercalado:\n");
    for (int i = 0; i < tamt; i++) {
        printf("%d ", particionar[i]);
    }
    printf("\n");

    return 0;
}
