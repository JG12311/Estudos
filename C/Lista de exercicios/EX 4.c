#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int X[15];
    int n, i, cont = 0;

    do{
        printf("Digite o tamanho do vetor com máximo 15 : ");
        scanf("%d",&n);
    }while(n > 15);

    printf("Digite os elementos do vetor\n");
    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i+1);
        scanf("%d", &X[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(X[i]> 30)
        {
           cont++;
        }
    }

    printf("Vetor lido\n");
    for ( i = 0; i < n; i++)
    {
        printf("Elemento %d: %d\n", i+1, X[i]);
    }
    printf("Números maior que 30: %d",cont);
    return 0;
}
