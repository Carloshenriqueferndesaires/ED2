#include<stdio.h>

int main(){

    FILE *arquivo;
    char nome[200];

    arquivo = fopen("novo.txt", "a+");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    while(fscanf(arquivo, "%s", nome) != EOF){
        printf("%s ", nome);
    }

    fclose(arquivo);
    return 0;   

}