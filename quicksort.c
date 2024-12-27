#include <stdio.h>
#include <string.h>
#include "ex7.h"

void quickSort(char str[], int menor, int maior) {
    int pivo;

    if (menor < maior) {
        pivo = particionar(str, menor, maior);

        quickSort(str, menor, pivo - 1);
        quickSort(str, pivo + 1, maior);
    }
}

int particionar(char str[], int menor, int maior) {
    int i, j;
    char pivo;

    pivo = str[maior];
    i = (menor - 1);

    for (j = menor; j <= maior - 1; j++) {
        if (str[j] < pivo) {
            i++;
            trocar(&str[i], &str[j]);
        }
    }
    trocar(&str[i + 1], &str[maior]);
    return (i + 1);
}

void trocar(char *a, char *b){
    char t;
    t = *a;
    *a = *b;
    *b = t;
}


int main() {
    char str[100];
    int n;

    printf("Digite uma string: ");
    scanf("%s", str);

    n = strlen(str);
    quickSort(str, 0, n - 1);

    printf("String ordenada: %s\n", str);

    return 0;
}
