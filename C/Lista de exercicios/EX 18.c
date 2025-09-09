#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float hipotenusa(float cat1, float cat2)
{
    float res;
    res= (cat1* cat1) + cat2*cat2;
    res = sqrt(res);
    return res;
}

void hipotenusav(float cat1, float cat2, float *r)
{
    *r = (cat1 * cat1) + (cat2 * cat2);
    *r = sqrt(*r);
}

int main()
{
    float cat1, cat2, r;

    printf("Digite o valor do primeiro cateto : ");
    scanf("%f",&cat1);
    printf("Digite o valor do segundo cateto : ");
    scanf("%f",&cat2);

    r = hipotenusa(cat1,cat2);
    hipotenusav(cat1,cat2, &r);
    printf("%.2f",r);

    return 0;

}
