#include <stdio.h>
#include <stdlib.h>

void main()
{
    int vetor[10]={0};

    printf("digite 10 numeros: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("\n%d", &vetor[i]);
 
        for (int i = 0; i <10; i++)
        {
            for (int i2 = i; i2 < 10; i2++)
            {
                if (vetor[i] > vetor[i2])
                {

                    int aux = vetor[i];
                    vetor[i] = vetor[i2];
                    vetor[i2] = aux;
                }
            }
        }
        printf("\n\n\nvetor Atual: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d  ", vetor[i]);
        }
    }

   
}