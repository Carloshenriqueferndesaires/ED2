#include<stdio.h>

int main(){

    FILE *arquivo;
    char nome;

    arquivo = fopen("dados.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while(fscanf(arquivo, "%c", &nome) != EOF){
        printf("%c", nome);
    }

    fclose(arquivo);
    return 0;
}