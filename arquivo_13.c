#include <stdio.h>

void insertionSort(int A[], int size)
{
    int j;
    int key;
    int i;

    for (j = 1; j < size; j++)
    {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1] = key;
    }
}

int main()
{
    FILE *arquivo;
    int A[4];
    int size = 0;
    int i;

    
    arquivo = fopen("insertion.bin", "wb");

    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "300\n");
    fprintf(arquivo, "200\n");
    fprintf(arquivo, "215\n");
    fprintf(arquivo, "201\n");

    fclose(arquivo);

    arquivo = fopen("insertion.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(arquivo, "%d", &A[size]) == 1)
    {
        size++;
    }

    fclose(arquivo);

   
    printf("Antes da ordenacao:\n");

    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    insertionSort(A, size);

    arquivo = fopen("insertion.bin", "wb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        fprintf(arquivo, "%d\n", A[i]);
    }

    fclose(arquivo);

   
    printf("Depois da ordenacao:\n");

    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}