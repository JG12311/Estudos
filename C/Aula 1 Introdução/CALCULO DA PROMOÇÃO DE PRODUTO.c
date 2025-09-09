#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    float price,discount,new_price;

    printf("\n\tDigite o valor do produto:\n\t");
    scanf("%f",&price);

    printf("\n\tDigite a porcentagem de desconto:\n\t");
    scanf("%f",&discount);

    new_price=price*((100-discount)/100);

    printf("\n\tO valor do produto com desconto é: R$%.2f\n\t",new_price);

    system("pause");
    return 0;

}
