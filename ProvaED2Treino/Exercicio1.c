#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define tamanhoDoEspaco 10
// arvora ABB arvore binaria de busca
typedef struct nodo
{
    int info;
    struct nodo *esq;
    struct nodo *dir;
} NO;
typedef NO *ARV;
int EMPTY(ARV a)
{
    return (a == NULL);
}
// Função para inserir um novo elemento 'b' na arvore 'a'
ARV insere(ARV a, int b)
{
    ARV nova;
    if (EMPTY(a))
    {
        nova = (ARV)malloc(sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        nova->info = b;
        printf("Insercao do numero %d na AB realizada!", b);
        return nova;
    }
    else
    {
        if (b > a->info)
            a->dir = insere(a->dir, b);
        else
            a->esq = insere(a->esq, b); /* Repeticoes sao inseridas na
            esquerda! */
        return a;
    }
}

void imprimir(NO *raiz, int espaco)
{
    // Caso base
    if (raiz == NULL)
    {
        return;
    }
    else
    {
        // Aumentar a distância entre os níveis
        espaco += tamanhoDoEspaco;

        // Trabalhando com a sub Arvore direita
        imprimir(raiz->dir, espaco);

        // Imprimir nó após o espaço
        printf("\n");
        for (int i = tamanhoDoEspaco; i < espaco; i++)
        {
            printf(" ");
        }

        printf("%d\n", raiz->info);

        // Trabalhando com a sub Arvore direita
        imprimir(raiz->esq, espaco);
    }
}

int alturaArvore(NO *raiz)
{

    int alturaDireita = 0;
    int alturaEsquerda = 0;

    if (raiz == NULL)
    {
        return -1;
    }

    alturaEsquerda = alturaArvore(raiz->esq);
    alturaDireita = alturaArvore(raiz->dir);

    if (alturaEsquerda > alturaDireita)
    {
        return alturaEsquerda + 1;
    }
    else
    {
        return alturaDireita + 1;
    }
}
void inOrder(ARV a)
{
    if (!EMPTY(a))
    {
        inOrder(a->esq);
        printf("%d", a->info);
        inOrder(a->dir);
    }
}

void posOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->info);
    }
}
void preOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        printf("%d ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}
ARV procura(ARV a, int b)
{
    if (EMPTY(a))
        return NULL;
    else if (a->info == b)
        return a;
    else if (b > a->info)
        return procura(a->dir, b);
    else
        return procura(a->esq, b);
}
// bool verificaAVL(ARV a)
// {
//     // Caso base: árvore vazia é AVL
//     if (a == NULL)
//         return true;

//     // Verifica o fator de balanceamento do nó atual
//     int balance = fatorBalanceamento(a);

//     // Verifica se o fator de balanceamento está dentro dos limites {-1, 0, 1}
//     if (balance < -1 || balance > 1)
//         return false;

//     // Verifica recursivamente a subárvore à esquerda e à direita
//     return verificaAVL(a->esq) && verificaAVL(a->dir);
// }

int main()
{
    ARV a = NULL;
    int opcao = 0;
    int num;
    while (opcao != 2)
    {
        system("cls");
        printf("\n\narvore e avl: ");
        if (verificaAVL(a))
            printf("\nsim\n\n");
        else
            printf("\nnao\n\n");
        break;
        printf("\n\n----------------MENU PRINCIPAL----------------");
        imprimir(a, tamanhoDoEspaco);
        printf("\n\n 1 - Inserir Novo Numero na AB");
        printf("\n 2 - Encerrar");
        printf("\naltura Atual: %d", alturaArvore(a));
        printf("\n\n Opcao Escolhida: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\nNovo Numero: ");
            scanf("%d", &num);
            a = insere(a, num);
            system("pause>>null");
            break;
        }
    }
    return 0;
}