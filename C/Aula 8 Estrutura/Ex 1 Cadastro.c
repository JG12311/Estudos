#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cadastro
{
    int RA;
    char nome[30];
    float nota[2];
} cad;

void leitura(cad A[])
{
    int i, j;

    for(i = 0; i < 30; i++)
    {
        printf("Digite o RA do %dº aluno: ", i + 1);
        scanf("%d", &A[i].RA);

        getchar(); // Limpa o buffer
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(A[i].nome, sizeof(A[i].nome), stdin);

        for(j = 0; j < 2; j++)
        {
            printf("Digite a nota %d do aluno %d: ", j + 1, i + 1);
            scanf("%f", &A[i].nota[j]);
        }
    }
}

float media(cad A[])
{
    int i;
    float res, maior = 0.0;

    for(i = 0; i < 30; i++)
    {
        res = (A[i].nota[0] + A[i].nota[1]) / 2.0;

        if(res > maior)
        {
            maior = res;
        }
    }

    return maior;
}

int rec(cad A[])
{
    int i, cont = 0;
    float res;

    for(i = 0; i < 30; i++)
    {
        res = (A[i].nota[0] + A[i].nota[1]) / 2.0;

        if(res < 5.0)
        {
            cont++;
        }
    }

    return cont;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    cad muito[30];
    float med;
    int contag;

    leitura(muito);
    med = media(muito);
    contag = rec(muito);

    printf("A maior média foi: %.2f\n", med);
    printf("Número de alunos em recuperação: %d\n", contag);

    return 0;
}

