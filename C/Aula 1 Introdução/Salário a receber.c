#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    float salario_base = 1500.00;
    float comissao_por_carro = 200.00;
    float percentual_venda = 0.05;
    int numero_carros_vendidos;
    float valor_total_vendas;
    float salario_total;
    float comissao_total;

    printf("\n\tDigite o n�mero de carros vendidos:");
    scanf("%d", &numero_carros_vendidos);

    printf("\n\tDigite o valor total das vendas: R$");
    scanf("%f", &valor_total_vendas);


    comissao_total = (numero_carros_vendidos * comissao_por_carro) + (valor_total_vendas * percentual_venda);


    salario_total = salario_base + comissao_total;


    printf("\n--- C�lculo do Sal�rio ---\n");
    printf("Sal�rio base: R$ %.2f\n", salario_base);
    printf("Comiss�o por carros vendidos: R$ %.2f\n", numero_carros_vendidos * comissao_por_carro);
    printf("Comiss�o de 5%% sobre o valor das vendas: R$ %.2f\n", valor_total_vendas * percentual_venda);
    printf("Sal�rio total do funcion�rio: R$ %.2f\n", salario_total);

    ("system pause");

    return 0;
}
