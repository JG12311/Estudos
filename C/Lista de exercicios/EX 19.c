#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fat(int num)
{
    int i,res = 1;

    if(num == 0)
    {
        return 1;
    }


    for(i = 1; i <= num; i++)
    {
        res = res * i;
    }
    return res;
}



int main()
{
    setlocale(LC_ALL,"portuguese");
    int resA,resB,resC;
    int a, b, c;
    printf("Digite o valor do primeiro n�mero: ");
    scanf("%d",&a);
    resA= fat(a);
    printf("Digite o valor do segundo n�mero: ");
    scanf("%d",&b);
    resB= fat(b);
    printf("Digite o valor do terceiro n�mero: ");
    scanf("%d",&c);
    resC= fat(c);

    printf("FATORIAL DE A � %d\n",resA);
    printf("FATORIAL DE B � %d\n",resB);
    printf("FATORIAL DE C � %d\n",resC);


    return 0;

}
