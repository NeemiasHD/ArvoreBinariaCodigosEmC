#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// arvora ABB arvore binaria de busca
#define tamanhoDoEspaco 10

typedef struct nodo
{
    char palavra[50]; // Mudança no tipo de dado para armazenar palavras
    struct nodo *esq;
    struct nodo *dir;
} NO;

typedef NO *ARV;

int EMPTY(ARV a)
{
    return (a == NULL);
}

ARV insere(ARV a, char palavra[])
{
    ARV nova;
    if (EMPTY(a))
    {
        nova = (ARV)malloc(sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        strcpy(nova->palavra, palavra);
        printf("Inserção da palavra %s na AB realizada!", palavra);
        return nova;
    }
    else
    {
        int comparacao = strcmp(palavra, a->palavra);
        if (comparacao > 0)
            a->dir = insere(a->dir, palavra);
        else
            a->esq = insere(a->esq, palavra);
        return a;
    }
}

void imprimir(NO *raiz, int espaco)
{
    if (raiz == NULL)
    {
        return;
    }
    else
    {
        espaco += tamanhoDoEspaco;
        imprimir(raiz->dir, espaco);
        printf("\n");
        for (int i = tamanhoDoEspaco; i < espaco; i++)
        {
            printf(" ");
        }

        printf("%s\n", raiz->palavra);
        imprimir(raiz->esq, espaco);
    }
}

void inOrder(ARV a)
{
    if (!EMPTY(a))
    {
        inOrder(a->esq);
        printf("%s ", a->palavra);
        inOrder(a->dir);
    }
}

void posOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%s ", a->palavra);
    }
}

void preOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        printf("%s ", a->palavra);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

ARV procura(ARV a, char palavra[])
{
    if (EMPTY(a))
        return NULL;
    else
    {
        int comparacao = strcmp(palavra, a->palavra);
        if (comparacao == 0)
            return a;
        else if (comparacao > 0)
            return procura(a->dir, palavra);
        else
            return procura(a->esq, palavra);
    }
}

int main()
{
    ARV a = NULL;
    int opcao = 0;
    char palavra[50];

    while (opcao != 2)
    {
        system("cls");
        printf("\n\nárvore e avl: ");
        // Ajuste a função de verificação de AVL conforme necessário (não implementada no código fornecido)
        printf("\n\n----------------MENU PRINCIPAL----------------");
        imprimir(a, tamanhoDoEspaco);
        printf("\n\n 1 - Inserir Nova Palavra na AB");
        printf("\n 2 - Encerrar");
        printf("\n\n Opção Escolhida: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\nNova Palavra: ");
            scanf("%s", palavra);
            a = insere(a, palavra);
            system("pause>>null");
            break;
        }
    }

    return 0;
}
