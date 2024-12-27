#include <stdio.h>
#include <string.h>
#include "ex6.h"

//Implementa o InsertionSort e o Selection Sort

void insertionSort(char nome[][100], int n) {
    int i, j;
    char nom[100];

    for (i = 1; i < n; i++) {
        strcpy(nom, nome[i]);
        j = i - 1;
        while (j >= 0 && strlen(nom) < strlen(nome[j])) {
            strcpy(nome[j + 1], nome[j]);
            j--;
        }
        strcpy(nome[j + 1], nom);
    }
}

void selectionSort(char nome[][100], int n) {
    int i, j, min;
    char nom[100];

    for (i = 0; i < n; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (strlen(nome[j]) < strlen(nome[min])) {
                min = j;
            }
        }
        if (min != i) {
            strcpy(nom, nome[i]);
            strcpy(nome[i], nome[min]);
            strcpy(nome[min], nom);
        }
    }
}

int main() {
    int n, op;
    printf("Digite a quantidade de nomes: ");
    scanf("%d", &n);

    char nome[n][100];

    for (int i = 0; i < n; i++) {
        printf("Digite um nome: ");
        scanf("%s", nome[i]);
    }

    printf("Escolha um tipo de ordenação (1 para Insertion ou 2 para selection): " );
    scanf("%d", &op);

    if (op==1){
        insertionSort(nome, n);
        printf("\nNomes ordenados por Insertion Sort:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", nome[i]);
        }
    }

    if (op==2){
        selectionSort(nome, n);
        printf("\nNomes ordenados por Selection Sort:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", nome[i]);
        }
    }

    return 0;
}
