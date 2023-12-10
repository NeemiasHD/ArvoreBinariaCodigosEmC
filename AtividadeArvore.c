#include <stdio.h>
#include <stdlib.h>

int criarProduto = 0;

typedef struct Produto
{
    int codigo;
    char nome[50], laboratorio[50];

    int preco;
} Produto;

Produto produto[50];

void CriarProduto()
{

    int codigo = criarProduto;
    char nome[50];
    double preco;
    printf("\n\ndigite o Nome do produto o laboratorio e o Preco: ");
    scanf("%[^\n]s", produto[codigo].nome);
    fflush(stdin);
    scanf("%[^\n]s", produto[codigo].laboratorio);
    fflush(stdin);
    scanf("%d", &produto[codigo].preco);
    produto[codigo].codigo = codigo;
    criarProduto++;
}

void PrintarProduto()
{
    system("cls");
    for (int i = 0; i < criarProduto; i++)
    {
        printf("\nCodigo do Produto: %d\nNome: %s\nLaboratorio:%s \nValor: %d\n\n\n", produto[i].codigo, produto[i].laboratorio, produto[i].nome, produto[i].preco);
    }
    system("pause");
}
void BuscarProdutoBinario(int valor)
{
    if (valor < 25)
    {
        for (int i = 25; i >= 0; i--)
        {
            if (i == valor)
            {
                printf("\nCodigo do Produto: %d\nNome: %s\nLaboratorio:%s \nValor: %d\n\n\n", produto[i].codigo, produto[i].laboratorio, produto[i].nome, produto[i].preco);
            }
        }
    }
    else
    {
        for (int i = 25; i < 50; i--)
        {
            if (i == valor)
            {
                printf("\nCodigo do Produto: %d\nNome: %s\nLaboratorio:%s \nValor: %d\n\n\n", produto[i].codigo, produto[i].laboratorio, produto[i].nome, produto[i].preco);
            }
        }
    }
    system("pause");
}
void BuscarProdutoNormal(int valor)
{
    for (int i = 0; i < 50; i++)
    {
        if (i == valor)
        {
            printf("\nCodigo do Produto: %d\nNome: %s\nLaboratorio:%s \nValor: %d\n\n\n", produto[i].codigo, produto[i].laboratorio, produto[i].nome, produto[i].preco);
        }
    }

    system("pause");
}

void main()
{

    int menu;
    do
    {

        system("cls");
        printf("-----Menu Farmacia-----\n\n");
        printf("1 - Criar Produto\n2 - Buscar Todos Produtos\n3 - Buscar 1 Produto Em binario\n4 - Buscar um Produto Normal\n");
        scanf("%d", &menu);
        fflush(stdin);
        if (menu == 1)
        {
            system("cls");
            CriarProduto();
        }
        else if (menu == 2)
        {

            PrintarProduto();
        }
        else if (menu == 3)
        {
            printf("\n\ndigite o produto que voce quer buscar: ");
            int buscar;
            scanf("%d", &buscar);
            BuscarProdutoBinario(buscar);
        }
        else if (menu == 4)
        {
            printf("\n\ndigite o produto que voce quer buscar: ");
            int buscar;
            scanf("%d", &buscar);
            BuscarProdutoNormal(buscar);
        }

    } while (menu != 0);
}