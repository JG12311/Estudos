#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 10



void inicializaTabuleiro(int tabuleiro[TAM][TAM])
{
    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tabuleiro[i][j] = rand() % 2;
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int contagemTabuleiromorto(int tabuleiro[TAM][TAM])
{
    int cont = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (tabuleiro[i][j] == 0)
            {
                cont++;
            }
        }
    }
    return cont;
}

int contagemTabuleirovivo(int tabuleiro[TAM][TAM])
{
    int cont = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (tabuleiro[i][j] == 1)
            {
                cont++;
            }
        }
    }
    return cont;
}

int contarVizinhos(int tabuleiro[TAM][TAM], int x, int y)
{
    int vizinhos = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i != 0 || j != 0)
            {
                int linha = x + i;
                int coluna = y + j;

                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM)
                {
                    vizinhos += tabuleiro[linha][coluna];
                }
            }
        }
    }
    return vizinhos;
}
void atualizarTabuleiro(int tabuleiro[TAM][TAM])
{
    int novoTabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            int vizinhos = contarVizinhos(tabuleiro, i, j);

            if (tabuleiro[i][j] == 1)
            {
                if (vizinhos == 2 || vizinhos == 3)
                {
                    novoTabuleiro[i][j] = 1;
                }
                else
                {
                    novoTabuleiro[i][j] = 0;
                }
            }
            else
            {
                if (vizinhos == 3)
                {
                    novoTabuleiro[i][j] = 1;
                }
                else
                {
                    novoTabuleiro[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tabuleiro[i][j] = novoTabuleiro[i][j];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int jogarNovamente = 1;
    int tabuleiro[TAM][TAM];
    int geracao;
    int cont_vivo,cont_morto;

    do
    {
        printf("\n========================================\n");
        printf("     BEM-VINDO AO JOGO DA VIDA\n");
        printf("========================================\n\n");

        printf(">> O Jogo da Vida de Conway é um jogo de lógica e autômato celular criado pelo matemático britânico John Horton Conway.\n");
        printf(">> É um jogo sem jogadores, onde a evolução é determinada pelo estado inicial.\n\n");
        system("pause");
        system("cls");


        printf("\n========================================\n");
        printf("                 REGRAS                   \n");
        printf("========================================\n\n");

        printf(">> Uma célula viva continua viva se tiver 2 ou 3 vizinhos vivos. Caso contrário, morre por solidão ou superpopulação.\n");
        printf(">> Uma célula morta torna-se viva se tiver exatamente 3 vizinhos vivos..\n");
        printf(">> A cada término de iteração o tabuleiro atual deve ser impresso para que se possa efetuar uma análise da população.\n");
        printf(">> Você irá escolher quantas gerações serão simuladas.\n\n");
        system("pause");
        system("cls");

        do
        {
            printf("Digite quantas gerações você quer:");
            scanf("%d",&geracao);

            system("cls");
            if(geracao <= 0)
            {
                printf("Número inválido.\n");
                printf("Digite novamente.\n\n");
                system("pause");
                system("cls");
            }


        }while(geracao <= 0);

        inicializaTabuleiro(tabuleiro);

        for(int i = 0; i < geracao; i++)
        {
            printf("Geração: %d:\n", i + 1);
            imprimirTabuleiro(tabuleiro);
            cont_morto = contagemTabuleiromorto(tabuleiro);
            cont_vivo  = contagemTabuleirovivo(tabuleiro);
            printf("Vivos:%d\nMortos:%d\n\n", cont_vivo, cont_morto);
            atualizarTabuleiro(tabuleiro);
        }


        system("pause");
        system("cls");
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

    }while(jogarNovamente == 1);
    printf("Obrigado por jogar!\nAté a próxima!");

    return 0;
}
