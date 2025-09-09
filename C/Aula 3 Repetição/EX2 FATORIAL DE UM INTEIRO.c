#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    int num,mult,fatorial;
    printf("\n\tDigite um número inteiro:");
    scanf("%d",&num);

    for(mult=1;mult<num;mult++)
    {
        fatorial=mult*num;
    }


 printf("%d",fatorial);
}






  system("pause");

    return 0;
}
