#include<stdio.h>

void escrever_vetor(int *v , int tam);
int ler_vetor(char *nome , int *v);

int main(){

    int vetor[200], tam;
    char nome[200];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    tam = ler_vetor(nome, vetor);
    escrever_vetor(vetor, tam);
    return 0;
}

void escrever_vetor(int *v , int tam){
    FILE *arquivo;
    int i;
    arquivo = fopen("vetor.txt", "w");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arquivo,"%d\n", tam);
    for( i = 0; i < tam; i++){
        fprintf(arquivo, "%d\n", v[i]);
    }
    fclose(arquivo);
}

int ler_vetor(char *nome , int *v){
    FILE *arquivo;
    int i;
    int tam;
    arquivo = fopen(nome, "r");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fscanf(arquivo,"%d", &tam);
    printf("%d\n", tam);
    for(i = 0; i < tam; i++){
        fscanf(arquivo, "%d", &v[i]);
        printf("[%d]\n", v[i]);
    }
    fclose(arquivo);
    return tam;
}