#include <stdio.h>
#include <locale.h>

float quad(float x)
{
    return x * x;
}

float somaQuadrados(float a, float b)
{
    return quad(a) + quad(b);
}

void lerNumeros(float *x, float *y)
{
    printf("Digite o primeiro número: ");
    scanf("%f", x);

    printf("Digite o segundo número: ");
    scanf("%f", y);
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    float n1, n2, resultado;

    lerNumeros(&n1, &n2);

    resultado = somaQuadrados(n1, n2);

    printf("A soma dos quadrados é: %.2f\n", resultado);

    return 0;
}
