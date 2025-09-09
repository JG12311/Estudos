#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int v[15];
    int i, contpar = 0, cont = 0;

    printf("Digite os elementos do vetor\n");
    for(i = 0; i < 15; i++)
    {
        printf("Elemento %d: ",i+1);
        scanf("%d",&v[i]);
    }

    for(i = 0; i < 15; i++)
    {
        if(v[i] % 2 == 0)
        {
            contpar++;
        }

        if(v[i] % 5 == 0)
        {
            cont++;
        }
    }
    printf("Números pares: %d\n",contpar);
    printf("Números multiplo de 5: %d\n",cont);

    return 0;
}
