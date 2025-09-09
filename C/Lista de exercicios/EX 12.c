#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    char carac, palavra[20];
    int i, cont = 0;

    printf("Digite a palavra: ");
    fgets(palavra, 20, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("Digite o caractere: ");
    scanf(" %c", &carac);

    for(i = 0; i < strlen(palavra); i++)
    {
        if(palavra[i] == carac)
        {
            cont++;
        }
    }

    printf("Esse caractere aparece %d vezes na string.\n", cont);

    return 0;
}

