#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int M[5][5];
    int condicao;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Elemento %d,%d :", i+1,j+1);
            scanf("%d",&M[i][j]);
        }

    }

    for(int i = 0; i< 5; i++)
    {
        for(int j = (i + 1);j < 5; j++)
        {
            if(M[i][j] != M[j][i])
            {
               condicao = 0;
            }
            else
            {
                condicao = 1;
            }
        }
        if( condicao ==0)
        {
            printf("\nNão é simétrico");
        }
        else
        {
            printf("\nÉ simétrico");
        }
        return 0;
    }
}
