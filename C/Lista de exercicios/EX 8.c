#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <stdio.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int vetor[8];
    int i, cont = 0;

    printf("Digite 8 números inteiros:\n");
    for (i = 0; i < 8; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor informado: ");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", vetor[i]);
    }


    for (i = 0; i < 8; i++)
    {
        if (vetor[i] > 30)
        {
            cont++;
        }
    }

    printf("\nQuantidade de números maiores que 30: %d\n", cont);

    return 0;
}
