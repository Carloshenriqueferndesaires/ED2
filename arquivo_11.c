#include <stdio.h>

typedef struct
{
    int chave;
    char A[10];
    char B[10];
    char C[10];
    char D[10];
} Registro;

int sequencial(FILE *arquivo, int ch)
{
    Registro registro;
    int e = 0;
    int i = 1;

    rewind(arquivo);

    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1)
    {

        if (registro.chave == ch)
        {
            e = i;

            break;
        }

        i++;
    }

    return e;
}


int main()
{
    FILE *arquivo;
    Registro dados[] = {
    {300, "A1", "B1", "C1", "D1"},
    {200, "A2", "B2", "C2", "D2"},
    {215, "A3", "B3", "C3", "D3"},
    {201, "A4", "B4", "C4", "D4"},
    {230, "A5", "B5", "C5", "D5"},
    {205, "A6", "B6", "C6", "D6"},
    {225, "A7", "B7", "C7", "D7"},
    {280, "A8", "B8", "C8", "D8"}
};
    
    int n;
    int chave=201;
    int e;

    arquivo = fopen("dados.dat", "wb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fwrite(dados, sizeof(Registro), 8, arquivo);


    e = sequencial(arquivo, chave);

    if (e == 0)
    {
        printf("Registro nao encontrado.\n");
    }
    else
    {
        printf("Registro encontrado!\n");
        printf(" chave: %d encontrado na Posicao: %d\n", chave, e);
    }

    fclose(arquivo);

    return 0;
}