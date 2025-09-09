#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int num,div;

    printf("\n\tDigite um número inteiro:");
    scanf("%d",&num);

    for(div=1;div<=num;div++)
    {
        if(num%div==0)
        {
            printf("\t%d\n",div);
        }
    }


    system("pause");
    return 0;
}
