#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int lado_1, lado_2, lado_3;

    printf("Digite o valor do primeiro lado: ");
    scanf("%d", &lado_1);

    printf("Digite o valor do segundo lado: ");
    scanf("%d", &lado_2);

    printf("Digite o valor do terceiro lado: ");
    scanf("%d", &lado_3);


    if (lado_1 + lado_2 > lado_3 && lado_1 + lado_3 > lado_2 && lado_2 + lado_3 > lado_1)
    {
        if (lado_1 == lado_2 && lado_1 == lado_3)
        {
            printf("\n\tO tri�ngulo � equil�tero\n");
        }
        else
        {
            if (lado_1 != lado_2 && lado_1 != lado_3 && lado_2 != lado_3)
            {
                printf("\n\tO tri�ngulo � escaleno\n");
            }
            else
            {
                printf("\n\tO tri�ngulo � is�sceles\n");
            }
        }
    }
    else
    {
        printf("\n\tOs valores informados n�o formam um tri�ngulo.\n");
    }

    return 0;
}
