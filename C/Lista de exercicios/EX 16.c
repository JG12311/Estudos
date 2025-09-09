#include <stdio.h>

void func( int a, int b)
{
    int i;
    if(a > b)
    {
        i = b;
        while( i <= a)
        {
            if (i % 2 == 0)
            {
                printf ("%d\n",i);
            }
            i++;
        }
    }
    else
    {
        i = a;
        while( i <= b)
        {
            if (i % 2 == 0)
            {
                printf ("%d\n",i);
            }
            i++;
        }
    }
}

int main()
{
    int a = 5, b = 10;
    func(a,b);
    return 0;

}
