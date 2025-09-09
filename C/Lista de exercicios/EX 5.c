#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int X[10], Y[10], Z[10];
    int i;

    printf("Digite o valor do primeiro vetor\n");
    for(i = 0; i < 10; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d",&X[i]);
    }

    printf("Digite o valor do segundo vetor\n");
    for(i = 0; i < 10; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d",&Y[i]);
    }

    for(i = 0; i < 10; i++)
    {
        Z[i] = X[i] + Y[i];
    }

    printf("Vetor Soma\n");
    for(i = 0; i < 10; i++)
    {
        printf("Elemento %d: %d\n",i + 1,Z[i]);
    }
    return 0;
}
