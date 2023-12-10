#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// nesse algoritimo de organização, é comparado o primeiro e o segundo elemento e se o primeiro for maior ele troca de lugar com o menor, com isso o menor sempre vai ficando em baixo e o maior sempre vai subindo forma
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// nesse algoritimo de organização, é separado em dois conjuntos, conjunto organizado e o desorganizado, o desorganizado faz uma comparação com o organizado pra ver aonde o numero se encaixa e é movido pro local correto, isso até acabar a lista e tudo estar organizado
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)//neste algoritimo de um elemento é comparado com todos os outros e com isso o menor sempre trocando de posição com os maiores até acabar o array
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                // Troca o menor elemento encontrado com o primeiro elemento não ordenado
                int temp = arr[min_idx];
                arr[min_idx] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main()
{
    const int size = 1000000;//aqui eu defino quantas posições meu vetor pode ter

    int *arr = (int *)malloc(size * sizeof(int));//aqui estou alocando dinamicamente um vetor com o tamanho definido pelo size

    // Preenchendo o vetor com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }

    clock_t start = clock();//inicio do Cronometro

    insertionSort(arr, size); //aqui eu defino qual algoritimo de organização usar.

    clock_t end = clock(); // final do Cronometro

    //Algoritimo de printar o arreio
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execucao do bubble Sort: %f segundos\n", cpu_time_used);
}
