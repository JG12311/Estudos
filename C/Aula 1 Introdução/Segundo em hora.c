#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int sec, hor, min, restante_sec;

    printf("\n\tDigite os segundos:\n\t");
    scanf("%i", &sec);

    hor = sec / 3600;          // Calcula o n�mero de horas
    min = (sec % 3600) / 60;   // Calcula o n�mero de minutos
    restante_sec = sec % 60;   // Calcula o n�mero de segundos restantes

    printf("\n\tN�mero de horas: %ih\n\t", hor);
    printf("\n\tN�mero de minutos: %imin\n\t", min);
    printf("\n\tN�mero de segundos: %is\n\t", restante_sec);

    system("pause");
    return 0;
}
