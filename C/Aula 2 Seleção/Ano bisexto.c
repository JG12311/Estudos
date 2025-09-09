#include <locale.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int ano;

    printf("\n\tDigite um ano: ");
    scanf("%d", &ano);


    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
        printf("\n\t%d é um ano bissexto.\n", ano);
        }
    else
        {
        printf("\n\t%d não é um ano bissexto.\n", ano);
        }

    return 0;
}
