#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int jogarNovamente;

    do
    {
        int cont, tentativa;
        int numero = 1000 + rand() % 9000;
        int d1, d2, d3, d4;
        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
        int acertosAtuais;
        int dica1_1 = 0, dica1_2 = 0;
        int dica2_1 = 0, dica2_2 = 0;
        int dica3_1 = 0, dica3_2 = 0;
        int dica4_1 = 0, dica4_2 = 0;

        d1 = numero / 1000;
        d2 = (numero % 1000) / 100;
        d3 = (numero % 100) / 10;
        d4 = numero % 10;

        printf("\n========================================\n");
        printf("     BEM-VINDO AO JOGO DA ADIVINHAÇÃO\n");
        printf("========================================\n\n");

        printf(">> Você tem 10 tentativas para descobrir o número secreto!\n");
        printf(">> O número esta entre 1000 e 9999.\n");
        printf(">> A partir da 5a tentativa, voce receberá dicas!\n\n");

        printf("Pressione ENTER para começar...");
        getchar();
        system("cls");

        int venceu = 0;

        for (cont = 1; cont <= 10; cont++)
        {
            system("cls");

            printf("\n========================================\n");
            printf("           TENTATIVA %d de 10\n", cont);
            printf("========================================\n");

            if (cont > 1)
            {
                printf("Ultimo palpite: %d %d %d %d\n", t1, t2, t3, t4);
                printf("Acertos permanentes: ");

                if (a1)
                {
                    printf("[%d] ", d1);
                }
                else
                {
                    printf("[ ] ");
                }
                if (a2)
                {
                    printf("[%d] ", d2);
                }
                else
                {
                    printf("[ ] ");
                }
                if (a3)
                {
                    printf("[%d] ", d3);
                }
                else
                {
                    printf("[ ] ");
                }
                if (a4)
                {
                    printf("[%d]", d4);
                }
                else
                {
                    printf("[ ]");
                }

                printf("\n");
            }

            printf("\nDigite um número entre 1000 e 9999: ");
            scanf("%d", &tentativa);

            if (tentativa < 1000 || tentativa > 9999)
            {
                printf("\n[!] Número fora do intervalo. Tente novamente.\n");
                cont--;
                system("pause");
                continue;
            }

            t1 = tentativa / 1000;
            t2 = (tentativa % 1000) / 100;
            t3 = (tentativa % 100) / 10;
            t4 = tentativa % 10;

            acertosAtuais = 0;
            if (t1 == d1)
            {
                a1 = 1;
                acertosAtuais++;
            }
            if (t2 == d2)
            {
                a2 = 1;
                acertosAtuais++;
            }
            if (t3 == d3)
            {
                a3 = 1;
                acertosAtuais++;
            }
            if (t4 == d4)
            {
                a4 = 1;
                acertosAtuais++;
            }

            if (acertosAtuais == 4)
            {
                printf("\n>> VOCE ACERTOU O NÚMERO SECRETO!\n");
                printf("Número secreto: %d %d %d %d\n", d1, d2, d3, d4);
                venceu = 1;
                system("pause");
                break;
            }

            printf("\nResultado desta tentativa:\n");
            printf("Posições corretas: %d/4\n", acertosAtuais);
            printf("Digitos: ");
            if (t1 == d1)
            {
                printf("[%d] ", t1);
            }
            else
            {
                printf("[ ] ");
            }
            if (t2 == d2)
            {
                printf("[%d] ", t2);
            }
            else
            {
                printf("[ ] ");
            }
            if (t3 == d3)
            {
                printf("[%d] ", t3);
            }
            else
            {
                printf("[ ] ");
            }
            if (t4 == d4)
            {
                printf("[%d]", t4);
            }
            else
            {
                printf("[ ]");
            }
            printf("\n");

            if (cont >= 5)
            {
                printf("\n*** DICA ESPECIAL ***\n");
                int dicaDada = 0;

                if (dicaDada == 0 && a1 == 0 && dica1_1 == 0)
                {
                    printf(">> 1o digito: %s\n", d1 % 2 == 0 ? "PAR" : "IMPAR");
                    dica1_1 = 1;
                    dicaDada = 1;
                }
                else if (dicaDada == 0 && a1 == 0 && dica1_2 == 0)
                {
                    printf(">> 1o digito: %s\n", d1 < 5 ? "MENOR que 5" : "5 ou MAIOR");
                    dica1_2 = 1;
                    dicaDada = 1;
                }

                if (dicaDada == 0 && a2 == 0 && dica2_1 == 0)
                {
                    printf(">> 2o digito: %s\n", d2 % 2 == 0 ? "PAR" : "IMPAR");
                    dica2_1 = 1;
                    dicaDada = 1;
                }
                else if (dicaDada == 0 && a2 == 0 && dica2_2 == 0)
                {
                    printf(">> 2o digito: %s\n", d2 < 5 ? "MENOR que 5" : "5 ou MAIOR");
                    dica2_2 = 1;
                    dicaDada = 1;
                }

                if (dicaDada == 0 && a3 == 0 && dica3_1 == 0)
                {
                    printf(">> 3o digito: %s\n", d3 % 2 == 0 ? "PAR" : "IMPAR");
                    dica3_1 = 1;
                    dicaDada = 1;
                }
                else if (dicaDada == 0 && a3 == 0 && dica3_2 == 0)
                {
                    printf(">> 3o digito: %s\n", d3 < 5 ? "MENOR que 5" : "5 ou MAIOR");
                    dica3_2 = 1;
                    dicaDada = 1;
                }

                if (dicaDada == 0 && a4 == 0 && dica4_1 == 0)
                {
                    printf(">> 4o digito: %s\n", d4 % 2 == 0 ? "PAR" : "IMPAR");
                    dica4_1 = 1;
                    dicaDada = 1;
                }
                else if (dicaDada == 0 && a4 == 0 && dica4_2 == 0)
                {
                    printf(">> 4o digito: %s\n", d4 < 5 ? "MENOR que 5" : "5 ou MAIOR");
                    dica4_2 = 1;
                    dicaDada = 1;
                }

                if (dicaDada == 0)
                {
                    printf(">> Dica geral: o numero eh %s que 5000\n",
                           numero > 5000 ? "MAIOR" : "MENOR ou IGUAL");
                }
            }

            printf("\n");
            system("pause");
        }

        system("cls");

        if (venceu)
        {
            printf("\n========================================\n");
            printf("             PARABENS!!\n");
            printf("========================================\n");
            printf(">> Você acertou em %d tentativa(s)!\n", cont);
            printf(">> Número secreto: %d %d %d %d\n", d1, d2, d3, d4);

            if (cont <= 3)
            {
                printf(">> Incrivel! Voce é um verdadeiro mestre desse jogo!\n");
            }
            else if (cont <= 6)
            {
                printf(">> Muito bom! Voce tem otima intuição!\n");
            }
            else
            {
                printf(">> Boa jogada! Com mais prática voce melhora ainda mais!\n");
            }
        }
        else
        {
            printf("\n========================================\n");
            printf("          FIM DE JOGO\n");
            printf("========================================\n");
            printf(">> O número era: %d %d %d %d\n", d1, d2, d3, d4);
            printf(">> Tente novamente, voce consegue!\n");
        }

        do
        {
            printf("\nDeseja jogar novamente?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            printf("Escolha: ");
            scanf("%d", &jogarNovamente);

            if (jogarNovamente != 1 && jogarNovamente != 2)
            {
                printf("Opção invalida. Tente novamente.\n");
            }
        }
        while (jogarNovamente != 1 && jogarNovamente != 2);

        system("cls");
    }
    while (jogarNovamente == 1);

    printf("\n========================================\n");
    printf("        Obrigado por jogar!\n");
    printf("           Até a próxima!\n");
    printf("========================================\n");

    return 0;
}
