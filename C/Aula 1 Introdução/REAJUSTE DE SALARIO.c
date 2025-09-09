#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    float sal,rea,novo;

    printf("\n\tDigite o salário mensal atual:\n\t");
    scanf("%f",&sal);

    printf("\n\tDigite a porcentagem de reajuste:\n\t");
    scanf("%f",&rea);

    novo=sal*((100+rea)/100);

    printf("\n\tO novo salário é: R$%.2f\n\t",novo);


    system("pause");
    return 0;

}
