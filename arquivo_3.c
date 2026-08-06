#include<stdio.h>
#include<locale.h> 

int main(){
    
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;
    char nome;

    arquivo = fopen("dados.txt", "w+");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo,"Ola! \nEscrevendo os meus dados aqui dentro do arquivo. \n meu nome é carlos e estou aprendendo a programar em c. \n");

    rewind(arquivo);

    while(fscanf(arquivo, "%c", &nome) != EOF){
        printf("%c", nome);
    }

    fclose(arquivo);
    return 0;
}