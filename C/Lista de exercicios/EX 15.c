#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    char palavra[10];
    printf ("Digite uma palavra:");
    fflush;
    fgets(palavra, 10, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    int sup= strlen(palavra)-1, inf=0, condicao = 1;
    while(inf<sup)
    {
        if(palavra[inf] != palavra[sup])
        {
            condicao = 0;
        }
        inf ++;
        sup --;

    }
    if (condicao == 1)
    {
        printf ("A palavra é palindroma");
    }
    else
    {
        printf ("A palavra não é palindroma");
    }
    return 0;
}
