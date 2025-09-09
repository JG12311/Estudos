#include <stdio.h>
#include <locale.h>

void somadiv(int x, int *y)
{
    int i;
    for(i = 1; i <= x; i++)
    {
        if(x % i == 0)
        {
            (*y) += i;
        }
    }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    int num, res = 0;
    do
    {
        printf("Digite um n�mero inteiro n�o negativo: ");
        scanf("%d",&num);
    }while(num <= 0);

    somadiv(num,&res);
    printf("A soma dos divisores � : %d",res);

    return 0;
}
