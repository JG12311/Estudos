#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b, int *c)
{
    int aux;
    aux= (*a);
    (*a) = (*c);
    (*c) = aux;
    aux = (*b);
    (*b) = (*a);
    (*a) = aux;
}

int main()
 {
    int x = 1, y = 2, z = 3;

    printf("Antes da troca:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    troca(&x, &y, &z);

    printf("Depois da troca:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}
