#include<stdio.h>

int main(){

    FILE *arquivo;
    char nome[200];

    arquivo = fopen("jogo.txt", "a+");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "jogo de luta:\n caracter 1: Ryu\n caracter 2: Ken\n caracter 3: Chun-Li\n caracter 4: Guile\n caracter 5: Blanka\n primeiro round: Ryu vs Ken\n segundo round: Chun-Li vs Guile\n terceiro round: Blanka vs Ryu\n quarto round: Ken vs Chun-Li\n quinto round: Guile vs Blanka\n");
    rewind(arquivo);
    while(fgets(nome, sizeof(nome), arquivo) != NULL){
        printf("%s", nome);
    }
    fclose(arquivo);
    return 0;
}