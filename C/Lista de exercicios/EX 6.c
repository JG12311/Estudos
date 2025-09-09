#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    float vetor[10];
    int i, negativos = 0;
    float soma = 0;

    printf("Digite 10 números reais:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }


    for (i = 0; i < 10; i++)
    {
        if (vetor[i] < 0)
        {
            negativos++;
        }
        else
        {
            soma+= vetor[i];
        }
    }

    printf("\nQuantidade de números negativos: %d\n", negativos);
    printf("Soma dos números positivos: %.2f\n", soma);

    return 0;
}
