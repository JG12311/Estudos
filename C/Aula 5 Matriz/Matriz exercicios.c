#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 4

int main()
{
    setlocale(LC_ALL,"portuguese");
    int lin,col,i,j,aux,a[TAM][TAM];

    printf("\n\tDigite o número de linhas da matriz:");
    scanf("%d",&lin);
    printf("\n\tDigite o número de colunas da matriz:");
    scanf("%d",&col);

    printf("\nDigite os valores da matriz (%dx%d):\n", lin, col);
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }























    return 0;
}
