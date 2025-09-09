#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct prod{
    int codigo;
    char nome[50];
    float preco;
    int quantidadeEstoque;
} Produto;

typedef struct vend{
    int codigoVenda;
    Produto produtoVendido;
    int quantidadeVendida;
    float valorTotal;
} Venda;

int verificaCodigoProduto(Produto produto[], int codigo, int contprod)
{
    for (int i = 0; i < contprod; i++)
    {
        if (produto[i].codigo == codigo)
        {
            return 0;
        }
    }
    return 1;
}

void cadastrarProduto(Produto produto[], int *contprod)
{
    system("cls");
    int codigoTemp;
    int valido = 0;

    if (*contprod >= 50)
    {
        printf("Limite de produtos atingido.\n");
        return ;
    }

    printf("======= CADASTRAR PRODUTO =======\n");
    while (valido == 0)
    {
        printf("Digite o código do produto: ");
        if (scanf("%d", &codigoTemp) != 1)
        {
            printf("Código inválido. Digite apenas números!\n");
            fflush(stdin);
        }
        else if (verificaCodigoProduto(produto, codigoTemp, *contprod) == 0)
        {
            printf("Código já cadastrado. Digite outro!\n");
        }
        else
        {
            valido = 1;
        }
    }

    produto[*contprod].codigo = codigoTemp;

    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(produto[*contprod].nome, 50, stdin);
    produto[*contprod].nome[strcspn(produto[*contprod].nome, "\n")] = '\0';

    printf("Digite o preço do produto: ");
    while (scanf("%f", &produto[*contprod].preco) != 1)
    {
        printf("Preço inválido. Digite um número válido: ");
        fflush(stdin);
    }

    printf("Digite a quantidade em estoque: ");
    while (scanf("%d", &produto[*contprod].quantidadeEstoque) != 1 || produto[*contprod].quantidadeEstoque <= 0)
    {
        printf("Quantidade inválida. Digite um número inteiro: ");
        fflush(stdin);
    }
    (*contprod)++;
    printf("Produto cadastrado com sucesso!\n");
}

void cadastrarVenda(Venda venda[], int *contvendas, Produto produto[], int contprod)
{
    if (*contvendas >= 100)
    {
        printf("Limite de vendas atingido.\n");
        system("pause");
        return;
    }
    if (contprod == 0)
    {
        system("cls");
        printf("Nenhum produto cadastrado. Cadastre um produto antes de registrar uma venda.\n");
        system("pause");
        return;
    }
    int erro, codVenda, codProd, produtoEncontrado,qtdVendida;

    do
    {
        system("cls");
        printf("======= CADASTRAR VENDA =======\n");
        erro = 0;

        printf("Digite o código da venda (-1 para cancelar): ");
        if (scanf("%d", &codVenda) != 1)
        {
            printf("Código inválido. Digite apenas números inteiros.\n");
            fflush(stdin);
            system("pause");
            erro = 1;
            continue;
        }

        if (codVenda == -1)
        {
            printf("Cadastro de venda cancelado.\n");
            system("pause");
            return;
        }

        for (int i = 0; i < *contvendas; i++)
        {
            if (venda[i].codigoVenda == codVenda)
            {
                printf("Código de venda já cadastrado!\n");
                system("pause");
                erro = 1;
                break;
            }
        }

        if (erro != 0)
            continue;

        printf("Digite o código do produto a ser vendido (-1 para cancelar): ");
        if (scanf("%d", &codProd) != 1)
        {
            printf("Código inválido. Digite apenas números inteiros.\n");
            fflush(stdin);
            system("pause");
            erro = 1;
            continue;
        }

        if (codProd == -1)
        {
            printf("Cadastro de venda cancelado.\n");
            system("pause");
            return;
        }

        produtoEncontrado = -1;
        for (int i = 0; i < contprod; i++)
        {
            if (produto[i].codigo == codProd)
            {
                produtoEncontrado = i;
                break;
            }
        }

        if (produtoEncontrado == -1)
        {
            printf("Produto não encontrado.\n");
            system("pause");
            erro = 1;
            continue;
        }

        printf("Digite a quantidade a ser vendida (-1 para cancelar): ");
        if (scanf("%d", &qtdVendida) != 1)
        {
            printf("Quantidade inválida. Digite apenas números válidos.\n");
            fflush(stdin);
            system("pause");
            erro = 1;
            continue;
        }

        if (qtdVendida == -1)
        {
            printf("Cadastro de venda cancelado.\n");
            system("pause");
            return;
        }

        if (qtdVendida <= 0)
        {
            printf("Quantidade inválida. Deve ser maior que zero.\n");
            system("pause");
            erro = 1;
        }
        else if (qtdVendida > produto[produtoEncontrado].quantidadeEstoque)
        {
            printf("Estoque insuficiente para essa venda.\n");
            system("pause");
            erro = 1;
        }

    } while (erro != 0);

    venda[*contvendas].codigoVenda = codVenda;
    venda[*contvendas].produtoVendido = produto[produtoEncontrado];
    venda[*contvendas].quantidadeVendida = qtdVendida;
    venda[*contvendas].valorTotal = qtdVendida * produto[produtoEncontrado].preco;

    produto[produtoEncontrado].quantidadeEstoque -= qtdVendida;

    (*contvendas)++;
    printf("Venda registrada com sucesso!\n");
    system("pause");
}

void gerarRelatorio(Produto relatorioproduto[], Venda relatoriovenda[], int contprod, int contvendas)
{
    int opcao;

    do {
        system("cls");
        printf("=================================================\n");
        printf("\tMENU DE OPÇÕES DE RELATÓRIO\n");
        printf("1 - Produto mais vendido\n");
        printf("2 - Total de vendas por produto\n");
        printf("3 - Valor total das vendas\n");
        printf("4 - Sair\n");
        printf("=================================================\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao)
        {
            case 1:
            {
                if (contvendas == 0)
                {
                    printf("Nenhuma venda registrada.\n");
                    system("pause");
                    break;
                }

                int pos = -1;
                int quantidadeMaximaVendida = 0;

                for (int i = 0; i < contprod; i++)
                {
                    int totalVendido = 0;

                    for (int j = 0; j < contvendas; j++)
                    {
                        if (relatoriovenda[j].produtoVendido.codigo == relatorioproduto[i].codigo)
                        {
                            totalVendido += relatoriovenda[j].quantidadeVendida;
                        }
                    }


                    if (totalVendido > quantidadeMaximaVendida)
                    {
                        quantidadeMaximaVendida = totalVendido;
                        pos = i;
                    }
                }

                if (pos == -1)
                {
                    printf("Nenhum produto foi vendido.\n");
                }
                else
                {
                    printf("\nProduto mais vendido:\n");
                    printf("Nome: %s\n", relatorioproduto[pos].nome);
                    printf("Código: %d\n", relatorioproduto[pos].codigo);
                    printf("Unidades vendidas: %d\n\n", quantidadeMaximaVendida);
                }

                system("pause");
                break;
            }

            case 2:
            {
                if (contvendas == 0)
                {
                    printf("Nenhuma venda registrada.\n");
                    system("pause");
                    break;
                }

                printf("Total de vendas por produto:\n");
                for (int i = 0; i < contprod; i++)
                {
                    int total_vendido = 0;
                    for (int j = 0; j < contvendas; j++)
                    {
                        if (relatoriovenda[j].produtoVendido.codigo == relatorioproduto[i].codigo)
                        {
                            total_vendido += relatoriovenda[j].quantidadeVendida;
                        }
                    }
                    printf("Produto: %s (Código %d): %d unidades vendidas\n",relatorioproduto[i].nome,relatorioproduto[i].codigo,total_vendido);
                }
                system("pause");
                break;
            }
            case 3:
            {
                if (contvendas == 0)
                {
                    printf("Nenhuma venda registrada.\n");
                    system("pause");
                    break;
                }

                float valor_total = 0;
                for (int i = 0; i < contvendas; i++)
                {
                    valor_total += relatoriovenda[i].valorTotal;
                }
                printf("Valor total das vendas: R$ %.2f\n", valor_total);
                system("pause");
                break;
            }
            case 4:
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
                break;
        }

    } while(opcao != 4);
}

void consultarProduto(Produto produto[], int contprod)
{
    system("cls");
    int codConsulta;
    int encontrado = 0;

    if (contprod == 0)
    {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }
    printf("======= CONSULTAR PRODUTO =======\n");
    for (int i = 0; i < contprod; i++)
    {
        printf("\n--- Produto %d ---\n",i + 1);
        printf("Código: %d\n", produto[i].codigo);
        printf("Nome: %s\n", produto[i].nome);
        printf("Preço: R$ %.2f\n", produto[i].preco);
        printf("Quantidade em estoque: %d\n\n", produto[i].quantidadeEstoque);
    }

}

void consultarVenda(Venda venda[], int contvendas)
{
    int codBusca;
    system("cls");

    if (contvendas == 0)
    {
        printf("Nenhuma venda cadastrada.\n");
        system("pause");
        return;
    }

    system("cls");
    printf("======= CONSULTAR VENDA =======\n");
    for (int i = 0; i < contvendas; i++)
    {
        printf("\n--- Venda %d ---\n",i + 1);
        printf("Código da venda: %d\n", venda[i].codigoVenda);
        printf("Produto vendido: %s\n", venda[i].produtoVendido.nome);
        printf("Código do produto: %d\n", venda[i].produtoVendido.codigo);
        printf("Preço unitário: R$ %.2f\n", venda[i].produtoVendido.preco);
        printf("Quantidade vendida: %d\n", venda[i].quantidadeVendida);
        printf("Valor total: R$ %.2f\n\n", venda[i].valorTotal);

    }

    printf("\n");
    system("pause");
}


void verificarprodutosemfalta(Produto produto[], int contprod) {
    system("cls");
    int encontrou = 0;

    printf("======= PRODUTOS EM FALTA =======\n");

    for (int i = 0; i < contprod; i++)
    {
        if (produto[i].quantidadeEstoque == 0)
        {
            printf("\n");
            printf("Código: %d\n", produto[i].codigo);
            printf("Nome: %s\n", produto[i].nome);
            printf("Preço: R$ %.2f\n", produto[i].preco);
            encontrou=1;
        }
    }

    if (encontrou==0)
    {
        printf("Nenhum produto em falta no momento.\n");
    }

    system("pause");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Produto produto[50];
    Venda venda[100];
    int opcao;
    int contprod = 0;
    int contvendas = 0;

    do {
        system("cls");

        printf("=================================================\n");
        printf("\tMENU DE OPÇÕES\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Cadastrar venda\n");
        printf("3 - Gerar relatório\n");
        printf("4 - Consultar Produto\n");
        printf("5 - Consultar Venda\n");
        printf("6 - Consultar produtos em falta\n");
        printf("7 - Sair\n");
        printf("=================================================\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                cadastrarProduto(produto, &contprod);
                system("pause");
                break;
            case 2:
                cadastrarVenda(venda, &contvendas, produto, contprod);
                break;
            case 3:
                gerarRelatorio(produto, venda, contprod, contvendas);
                break;
            case 4:
                consultarProduto(produto, contprod);
                system("pause");
                break;
            case 5:
                consultarVenda(venda, contvendas);
                break;
            case 6:
                verificarprodutosemfalta(produto, contprod);
                break;
            case 7:
                system("cls");
                printf("Saindo do Programa\n");
                system("pause");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
                break;
        }

    } while (opcao != 7);

    return 0;
}
