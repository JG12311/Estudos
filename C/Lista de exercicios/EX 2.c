#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int X[20], Z[20];
    int n, k, i;

    do{
        printf("Digite o tamanho do vetor com máximo 20:");
        scanf("%d",&n);
    }while(n>20);

    printf("\nDigite o elemento que k que vai multiplicar o vetor: ");
        scanf("%d",&k);

    printf("\nDigite os elementos do vetor\n");
    for(i = 0; i < n; i++)
    {
        printf("\nElemento %d: ",i + 1);
        scanf("%d",&X[i]);
    }

    for(i = 0; i < n; i++)
    {
        Z[i] = X[i] * k;
    }
    printf("\nVetor lido:");
    for(i = 0; i < n; i++)
    {
        printf("\nElemento %d: %d\n",i+1,X[i]);

    }
    printf("\nValor de k:%d",k);

    printf("\nVetor multiplicado por k:");
    for(i = 0; i < n; i++)
    {
        printf("\nElemento %d: %d\n",i+1,Z[i]);

    }







    return 0;
}
