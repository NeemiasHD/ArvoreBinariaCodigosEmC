#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define tamanhoDoEspaco 10
typedef struct nodo
{
    int info;
    int altura; // Adicionamos a altura ao nó
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

// Função para calcular a altura de um nó
int altura(NO *n)
{
    if (n == NULL)
        return -1;
    return n->altura;
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento(NO *n)
{
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
}

// Função para rotacionar a subárvore à direita
NO *rotacaoDireita(NO *y)
{
    NO *x = y->esq;
    NO *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    // Atualiza as alturas
    y->altura = (altura(y->esq) > altura(y->dir) ? altura(y->esq) : altura(y->dir)) + 1;
    x->altura = (altura(x->esq) > altura(x->dir) ? altura(x->esq) : altura(x->dir)) + 1;

    return x;
}

// Função para rotacionar a subárvore à esquerda
NO *rotacaoEsquerda(NO *x)
{
    NO *y = x->dir;
    NO *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = (altura(x->esq) > altura(x->dir) ? altura(x->esq) : altura(x->dir)) + 1;
    y->altura = (altura(y->esq) > altura(y->dir) ? altura(y->esq) : altura(y->dir)) + 1;

    return y;
}

// Função para inserir um novo elemento 'b' na árvore 'a'
ARV insere(ARV a, int b)
{
    if (EMPTY(a))
    {
        NO *nova = (NO *)malloc(sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        nova->info = b;
        nova->altura = 0;
        return nova;
    }

    if (b < a->info)
    {
        a->esq = insere(a->esq, b);
    }
    else if (b > a->info)
    {
        a->dir = insere(a->dir, b);
    }
    else
    {
        // Ignora elementos duplicados
        return a;
    }

    // Atualiza a altura do nó atual
    a->altura = 1 + ((altura(a->esq) > altura(a->dir)) ? altura(a->esq) : altura(a->dir));

    // Calcula o fator de balanceamento
    int balance = fatorBalanceamento(a);

    // Casos de desequilíbrio e rotações
    if (balance > 1 && b < a->esq->info)
    {
        return rotacaoDireita(a);
    }
    if (balance < -1 && b > a->dir->info)
    {
        return rotacaoEsquerda(a);
    }
    if (balance > 1 && b > a->esq->info)
    {
        a->esq = rotacaoEsquerda(a->esq);
        return rotacaoDireita(a);
    }
    if (balance < -1 && b < a->dir->info)
    {
        a->dir = rotacaoDireita(a->dir);
        return rotacaoEsquerda(a);
    }

    return a;
}

// Percorrer a árvore em pós-ordem
void posOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->info);
    }
}

// Percorrer a árvore em pré-ordem
void preOrdem(ARV a)
{
    if (!EMPTY(a))
    {
        printf("%d ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

// Função para calcular a altura da árvore AVL
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
    printf(" 1 - Inserir Numeros na Arvore AVL\n");
    printf(" 2 - Imprimir Arvore (Pos-ordem)\n");
    printf(" 3 - Imprimir Arvore (Pre-ordem)\n");
    printf(" 4 - Calcular Altura da Arvore AVL\n");
    printf(" 5 - a Arvore e AVL?\n");
    printf(" 6 - Sair\n");
    printf("\n Opcao Escolhida: ");
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

bool verificaAVL(ARV a)
{
    // Caso base: árvore vazia é AVL
    if (a == NULL)
        return true;

    // Verifica o fator de balanceamento do nó atual
    int balance = fatorBalanceamento(a);

    // Verifica se o fator de balanceamento está dentro dos limites {-1, 0, 1}
    if (balance < -1 || balance > 1)
        return false;

    // Verifica recursivamente a subárvore à esquerda e à direita
    return verificaAVL(a->esq) && verificaAVL(a->dir);
}

int main()
{
    ARV arvore = NULL;
    int opcao = 0;
    char entrada[50]; // Tamanho arbitrário para a entrada

    do
    {
        system("pause");
        system("cls");
        imprimir(arvore, tamanhoDoEspaco);
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
            printf("\nArvore AVL (Pos-ordem): ");
            posOrdem(arvore);
            printf("\n");
            break;

        case 3:
            printf("\nArvore AVL (Pre-ordem): ");
            preOrdem(arvore);
            printf("\n");
            break;

        case 4:
            printf("\nAltura da Arvore AVL: %d\n", alturaArvore(arvore));
            break;

        case 6:
            printf("\nEncerrando o programa.\n");
            break;
        case 5:
            printf("\n\narvore e avl: ");
            if (verificaAVL(arvore))
                printf("\nsim\n\n");
            else
                printf("\nnao\n\n");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
