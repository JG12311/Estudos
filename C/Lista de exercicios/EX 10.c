#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int V[20], X, i, encontrado = 0;

    printf("Digite os números do vetor\n");
    for(i = 0; i < 20; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &V[i]);
    }

    printf("\nDigite o valor X: ");
    scanf("%d", &X);

    printf("\n");

    for(i = 0; i < 20; i++)
    {
        if(V[i] == X)
        {
            printf("O valor de X foi encontrado na posição %d\n", i);
            encontrado = 1;
        }
    }

    if(encontrado == 0)
    {
        printf("O valor de X não foi encontrado\n");
    }

    return 0;
}

