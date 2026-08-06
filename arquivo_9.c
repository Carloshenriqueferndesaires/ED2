#include<stdio.h>
#include<stdlib.h>

typedef struct _FUNCIONARIO {
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} FUNCIONARIO;

void salvarFuncionario(FUNCIONARIO *funcionario, FILE *arquivo  ) {
    
    fwrite(&funcionario->cod, sizeof(int), 1, arquivo);
    fwrite(funcionario->nome, sizeof(char), 50, arquivo);
    fwrite(funcionario->cpf, sizeof(char), 15, arquivo);
    fwrite(funcionario->data_nascimento, sizeof(char), 11, arquivo);
    fwrite(&funcionario->salario, sizeof(double), 1, arquivo);
}

FUNCIONARIO *lerFuncionario(FILE *arquivo) {
   
    FUNCIONARIO *funcionario = (FUNCIONARIO *)malloc(sizeof(FUNCIONARIO));
    
    fread(&funcionario->cod, sizeof(int), 1, arquivo);
    fread(funcionario->nome, sizeof(char), 50, arquivo);
    fread(funcionario->cpf, sizeof(char), 15, arquivo);
    fread(funcionario->data_nascimento, sizeof(char), 11, arquivo);
    fread(&funcionario->salario, sizeof(double), 1, arquivo);

    return funcionario;
}

int main(){
    
    FILE *arquivo;
    
    FUNCIONARIO funcionario = {1, "Joao da Silva", "123.456.789-00", "01/01/1990", 2500.00};
    arquivo = fopen("funcionarios.bin", "wb+");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    salvarFuncionario(&funcionario, arquivo);    
    printf("Funcionarios salvos com sucesso!\n");

    rewind(arquivo); 

    FUNCIONARIO *funcionario_lido = lerFuncionario(arquivo);
    if (funcionario_lido != NULL) {
        printf("Funcionario lido:\n %d\n, %s\n, %s\n, %s\n, %.2f\n", funcionario_lido->cod, funcionario_lido->nome, funcionario_lido->cpf, funcionario_lido->data_nascimento, funcionario_lido->salario);
        free(funcionario_lido);
    }

    fclose(arquivo);
    return 0;

}