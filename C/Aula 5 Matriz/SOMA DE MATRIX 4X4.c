#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 4

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, a[TAM][TAM], b[TAM][TAM], c[TAM][TAM];

    // Primeira matriz
    printf("\nDigite os valores da primeira matriz (%dx%d):\n", TAM, TAM);
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Segunda matriz
    printf("\nDigite os valores da segunda matriz (%dx%d):\n", TAM, TAM);
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // Soma das matrizes
    printf("\nA matriz resultante da soma:\n");
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%4d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
