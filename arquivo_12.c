#include<stdio.h>

typedef struct {
    int chave;
    char A[10];
    char B[10];
    char C[10];
    char D[10];
} Registro;

int seq_ordenada(FILE *arquivo, int ch)
{
    Registro registro;
    int e = 0;
    int i = 1;
    int n = 8;

    rewind(arquivo);

  
    fread(&registro, sizeof(Registro), 1, arquivo);

    while ((registro.chave < ch) && (i < n))
    {
        i++;

        fread(&registro, sizeof(Registro), 1, arquivo);
    }

    if (registro.chave == ch)
    {
        e = i;
    }

    return e;
}

int main()
{
    FILE *arquivo;

    Registro dados[] = {
        {200, "A2", "B2", "C2", "D2"},
        {201, "A4", "B4", "C4", "D4"},
        {205, "A6", "B6", "C6", "D6"},
        {215, "A3", "B3", "C3", "D3"},
        {225, "A7", "B7", "C7", "D7"},
        {230, "A5", "B5", "C5", "D5"},
        {280, "A8", "B8", "C8", "D8"},
        {300, "A1", "B1", "C1", "D1"}
    };

    int chave = 202;
    int e;
    int n =8;

    arquivo = fopen("ed2.dat", "wb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }


    fwrite(dados, sizeof(Registro), n, arquivo);

    e = seq_ordenada(arquivo, chave);

  
    if (e == 0)
    {
        printf("Registro nao encontrado.\n");
    }
    else
    {
        printf("Registro encontrado!\n");
        printf("Chave %d encontrada na posicao %d.\n", chave, e);
    }

    fclose(arquivo);

    return 0;
}