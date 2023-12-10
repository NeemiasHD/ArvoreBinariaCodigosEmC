#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Função para remover caracteres especiais
void removeEspeciais(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] < 0 || !isalnum((unsigned char)str[i]))
        {
            str[i] = ' ';
        }
    }
}

// Função para inserir um novo elemento 'b' na árvore 'a'
ARV insere(ARV a, int b)
{
    ARV nova;
    if (EMPTY(a))
    {
        nova = (ARV)malloc(sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        nova->info = b;
        return nova;
    }
    else
    {
        if (b > a->info)
            a->dir = insere(a->dir, b);
        else
            a->esq = insere(a->esq, b);
        return a;
    }
}

// Percorrer a árvore em pós-ordem printa esquerda depois direita depois o topo.
void posOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->info);
    }
}

// Percorrer a árvore em pré-ordem printa primeiro o topo depois esquerda depois direita
void preOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        printf("%d ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

// Função para calcular a altura de uma árvore binária

// a arvore é passada por parametro aonde ela atravez da recursão é calculado a profundidade da arvore,cada lado recebe o valor da profundidade, e o maior é retornardo, e calculado a altura final.
int alturaArvore(ARV a)
{
    if (EMPTY(a))
        return -1;
    else
    {
        int alturaEsq = alturaArvore(a->esq);
        int alturaDir = alturaArvore(a->dir);

        return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
    }
}

// Função para exibir o menu interativo
void exibirMenu()
{
    printf("\n\n----------------MENU----------------\n");
    printf(" 1 - Inserir Numeros na Arvore\n");
    printf(" 2 - Imprimir Arvore (Pos-ordem)\n");
    printf(" 3 - Imprimir Arvore (Pre-ordem)\n");
    printf(" 4 - Calcular Altura da Arvore\n");
    printf(" 5 - Sair\n");
    printf("\n Opcao Escolhida: ");
}

int main()
{
    ARV arvore = NULL;
    int opcao = 0;
    char entrada[50]; // Tamanho arbitrário para a entrada

    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nNovo Numero: ");
            scanf("%s", entrada);
            removeEspeciais(entrada);
            arvore = insere(arvore, atoi(entrada));
            break;

        case 2:
            printf("\nArvore (Pos-ordem): ");
            posOrdem(arvore);
            printf("\n");
            break;

        case 3:
            printf("\nArvore (Pre-ordem): ");
            preOrdem(arvore);
            printf("\n");
            break;

        case 4:
            printf("\nAltura da Arvore: %d\n", alturaArvore(arvore));
            break;

        case 5:
            printf("\nEncerrando o programa.\n");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
