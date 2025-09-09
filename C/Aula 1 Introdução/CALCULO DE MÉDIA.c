#include <stdio.h>
#include <stdlib.h>

int main()
{
    float NOTA_1,NOTA_2,MEDIA;
    NOTA_1=NOTA_2=MEDIA=0.0;

    printf("\nDIGITE O VALOR DA NOTA 1\n");
    scanf("%f",&NOTA_1);

    printf("\nDIGITE O VALOR DA NOTA 2\n");
    scanf("%f",&NOTA_2);

    MEDIA=(NOTA_1+NOTA_2)/2;

    printf("RESULTADO DA MEDIA: %.2f\n",MEDIA);
    system("pause");


    return 0;
}
