#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    int senha=2806,tent,cont;

    for(cont=1;tent!=senha;cont++)
    {
        printf("\n\tDigite a senha:");
        scanf("%d",&tent);
        if(tent==senha)
        {
            printf("\n\tACESSO LIBERADO!!!\n\t");
        }

        else
        {
            if(cont==3)
            {
                printf("\n\tMÁXIMO DE TENTATIVAS ATINGIDAS!!!\n\tACESSO BLOQUEADO\n\t");
                break;
            }
            else
            {
                printf("\n\tTENTE NOVAMENTE");
            }

        }

    }
    system("pause");
    return 0;
}
