#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    float vetor[10];
    int i, qtd_negativos = 0;
    float soma_positivos = 0;


    printf("Digite 10 n�meros reais:\n");
    for (i = 0; i < 10; i++)
    {
        printf("N�mero %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }


    for (i = 0; i < 10; i++)
    {
        if (vetor[i] < 0)
        {
            qtd_negativos++;
        }
        else
        {
            soma_positivos += vetor[i];
        }
    }

    printf("\nQuantidade de n�meros negativos: %d\n", qtd_negativos);
    printf("Soma dos n�meros positivos: %.2f\n", soma_positivos);

    return 0;
}
