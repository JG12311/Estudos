#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int numero, soma;

    printf("\n\tDigite um número inteiro de 2 dígitos:\n\t");
    scanf("%d", &numero);

    int primeiro_digito = numero / 10;
    int segundo_digito = numero % 10;
    soma = primeiro_digito + segundo_digito;

    printf("A soma dos dígitos de %d é: %d\n", numero, soma);

    return 0;
}
