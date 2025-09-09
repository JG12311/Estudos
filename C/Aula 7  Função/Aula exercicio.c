#include <stdio.h>

void ler(int *a)
{
    printf("Digite um valor inteiro: ");
    scanf("%d",a);
}

int main()
{
    int x;
    ler(&x);
    printf("\n\tx = %d\n\n",x);
}
