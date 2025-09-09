#include <stdio.h>
#include <locale.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[101];
    int i, tamanho;

    printf("Digite o nome completo: ");
    fflush(stdin);
    gets(nome);

    tamanho = strlen(nome);

    if (nome[0] != ' ')
    {
        printf("%c", nome[0]);
    }


    for (i = 1; i < tamanho; i++)
        {
        if (nome[i - 1] == ' ' && nome[i] != ' ')
        {
            printf("%c", nome[i]);
        }
    }

    printf("\n");
    return 0;
}
