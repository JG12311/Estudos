#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int num;
    printf("\n\tDigite um n�mero inteiro\n\t");
    scanf("%d",&num);

    if(num%2==0)
    {
        printf("\n\t O n�mero %d � impar\n",num);
    }
    else
    {
        printf("\n\tO n�mero %d � impar\n",num);
    }


    return 0;
}
