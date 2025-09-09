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
    printf("Digite o valor do primeiro número: ");
    scanf("%d",&a);
    resA= fat(a);
    printf("Digite o valor do segundo número: ");
    scanf("%d",&b);
    resB= fat(b);
    printf("Digite o valor do terceiro número: ");
    scanf("%d",&c);
    resC= fat(c);

    printf("FATORIAL DE A é %d\n",resA);
    printf("FATORIAL DE B é %d\n",resB);
    printf("FATORIAL DE C é %d\n",resC);


    return 0;

}
