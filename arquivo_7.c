#include<stdio.h>

int main(){

    FILE *arquivo;
    
    arquivo = fopen("binario.bin", "wb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char vetor[100]= "Ola! Escrevendo os meus dados aqui dentro do arquivo.";
    fwrite(vetor, sizeof(char), 100, arquivo);

    fclose(arquivo);
    
    printf("Programa finalizado e texto lido!\n");
    return 0;
}