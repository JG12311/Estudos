#include <stdio.h>
#include <stdlib.h>
//exercicio 4
int pedigit(int num ,int d)
{

    if(num == 0)
    {
        return 0;
    }
    if (num % 10 == d)
    {
        return 1+ pedigit(num/10, d);
    }
    return pedigit(num/10,d);
}


//exercicio 5
int func_contagem(int C[],int c)
{
    if(c == 0)
    {
        return C[c];
    }
    if(c%2==0)
    {
        return C[c] + func_contagem(C,c-1);
    }
    return func_contagem(C,c-1);
}

int main()
{
    int V[10],s=9;
    printf("%d",func_contagem(V,s));
    return 0;
}
