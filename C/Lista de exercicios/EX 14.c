#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    char texto[11];
    int i, tamanho;

    printf("Digite uma string de até 10 caracteres: ");
    fflush(stdin);
    gets(texto);

    tamanho = strlen(texto);

    printf("String sem vogais: ");
    for (i = 0; i < tamanho; i++)
        {
        if (texto[i] != 'a' && texto[i] != 'e' && texto[i] != 'i' && texto[i] != 'o' && texto[i] != 'u' && texto[i] != 'A' && texto[i] != 'E' && texto[i] != 'I' && texto[i] != 'O' && texto[i] != 'U')
        {
            printf("%c", texto[i]);
        }
    }

    printf("\n");
    return 0;
}
