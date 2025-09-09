#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int X[20], Y[20], Z[20];
    int i , n;

    do
    {
       printf("Digite o tamanho do vetor:");
       scanf("%d",&n);
    }while(n>20);



    printf("Digite os valores do primeiro vetor:\n");
    for(i = 0; i < n;i++)
    {
        printf("Elemento %d: ", i+1);
        scanf("%d",&X[i]);
    }

    printf("Digite os valores do segundo vetor:\n");
    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i+1);
        scanf("%d",&Y[i]);
    }
    for(i = 0; i < n; i++)
    {
        Z[i] = X[i] * Y[i];
    }

    printf("O produto dos vetores é igual:\n");
    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: %d\n",i+1,Z[i]);
    }



    return 0;
}
