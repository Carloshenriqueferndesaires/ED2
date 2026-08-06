#include<stdio.h>

int main(){

    FILE *arquivo;
    
    arquivo = fopen("binario.bin", "rb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char vetor[100];
    fread(vetor, sizeof(char), 100, arquivo);

    for(int i = 0; i < 100; i++){
        printf("%c\n", vetor[i]);
    }

    fclose(arquivo);
    
    printf("Programa finalizado e texto lido!\n");
    return 0;
}