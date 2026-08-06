#include<stdio.h>

int main(){

    FILE *arquivo;
    
    arquivo = fopen("dados.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao criar/abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Ola! Escrevendo os meus dados aqui dentro do arquivo.");

    fclose(arquivo);
    
    printf("Programa finalizado e texto gravado!\n");
    return 0;
}