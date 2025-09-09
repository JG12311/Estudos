#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int num;
    printf("\n\tDigite um número inteiro\n\t");
    scanf("%d",&num);

    if(num%2==0)
    {
        printf("\n\t O número %d é impar\n",num);
    }
    else
    {
        printf("\n\tO número %d é impar\n",num);
    }


    return 0;
}
