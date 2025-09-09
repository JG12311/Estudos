#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int num,rep,res;
    printf("\n\tDigite um número inteiro entre 1 e 10\n\t---> ");
    scanf("%d",&num);
    printf("\n\tA tabuada do %d é",num);

    for(rep=1;rep<=10;rep++)
    {
       res=num*rep;
       printf("\n\t%d X %d = %d",num,rep,res);
    }

    return 0;
}
