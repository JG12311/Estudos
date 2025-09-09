#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int sec, hor, min, restante_sec;

    printf("\n\tDigite os segundos:\n\t");
    scanf("%i", &sec);

    hor = sec / 3600;          // Calcula o número de horas
    min = (sec % 3600) / 60;   // Calcula o número de minutos
    restante_sec = sec % 60;   // Calcula o número de segundos restantes

    printf("\n\tNúmero de horas: %ih\n\t", hor);
    printf("\n\tNúmero de minutos: %imin\n\t", min);
    printf("\n\tNúmero de segundos: %is\n\t", restante_sec);

    system("pause");
    return 0;
}
