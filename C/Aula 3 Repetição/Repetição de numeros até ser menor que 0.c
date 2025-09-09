#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int num, soma = 0, cont = 1, menor;

    // Inicializa num com um valor positivo para entrar no loop
    num = 1;
    menor = 0;  // Inicialização correta

    printf("\n\tDigite um número inteiro:");
    scanf("%d", &num);

    // Inicializar "menor" corretamente
    if (num > 0)
        {
        menor = num;
        }

    while (num > 0)
    {
        if (num < menor)
        {
            menor = num;
        }

        if (num % 2 == 0)
        {
            soma += num;
        }

        cont++;

        printf("\n\tDigite um número inteiro: ");
        scanf("%d", &num);
    }

    if (cont > 0) {
        printf("\n\tO menor número foi: %d", menor);
        printf("\n\tA soma dos números pares foi: %d", soma);
        printf("\n\tA quantidade de números digitados foi: %d\n", cont);
    } else {
        printf("\n\tNenhum número válido foi digitado.\n");
    }

    return 0;
}
