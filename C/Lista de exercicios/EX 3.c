#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int X[20];
    int n, s = 0 , i;

    do{
        printf("Digite o tamanho do vetor com m�ximo 20:");
        scanf("%d",&n);
    }while(n>20);

    printf("Digite os elementos do vetor\n");
    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: ",i+1);
        scanf("%d",&X[i]);
    }

    for(i = 0; i < n; i++)
    {
        s +=  X[i];
    }

    printf("Vetor lido:\n");
    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: %d\n",i+1,X[i]);

    }
    printf("\nO somat�rio dos vetores �: %d",s);
    return 0;
}
