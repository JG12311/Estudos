#include <stdio.h>
#include <stdlib.h>


float calculo(float x, float y, float z)
{
    float res;
    res= (x*x) + y + z;

    return res;
}

void calculov(float x, float y, float z , float *r)
{
    (*r) = (x*x) + y + z;

}

int main()
{
    float a, b, c, r = 0 ;

    printf("Digite o valor de a: ");
    scanf("%f",&a);

    printf("Digite o valor de b: ");
    scanf("%f",&b);

    printf("Digite o valor de c: ");
    scanf("%f",&c);

    r = calculo(a, b, c);
    calculov(a, b, c, &r);
    printf ("%.2f",r);

    return 0;
}
