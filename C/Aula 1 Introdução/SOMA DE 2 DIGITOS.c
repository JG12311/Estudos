#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int numero, soma;

    printf("\n\tDigite um n�mero inteiro de 2 d�gitos:\n\t");
    scanf("%d", &numero);

    int primeiro_digito = numero / 10;
    int segundo_digito = numero % 10;
    soma = primeiro_digito + segundo_digito;

    printf("A soma dos d�gitos de %d �: %d\n", numero, soma);

    return 0;
}
