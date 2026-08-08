#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int codigo;
    char nome[50];
    char gerente[50];
}AGENCIA;

typedef struct {
    int codigo;
    int codigo_agencia;
    double saldo;
}CONTA_CORRENTE;

void cadastrar_agencia() {
    FILE *agencia;
    AGENCIA ag;

    agencia = fopen("agencias.dat", "ab");
    
    if (agencia == NULL) {
        printf("Erro ao abrir o arquivo de agencias.\n");
        return;
    }

    printf("Digite o codigo da agencia: ");
    scanf("%d", &ag.codigo);
    printf("Digite o nome da agencia: ");
    scanf("%s", ag.nome);
    printf("Digite o nome do gerente: ");
    scanf("%s", ag.gerente);

    fwrite(&ag.codigo, sizeof(int), 1, agencia);
    fwrite(ag.nome, sizeof(char), 50, agencia);
    fwrite(ag.gerente, sizeof(char), 50, agencia);

    fclose(agencia);
}

void ler_agencias() {
    FILE *agencia;
    AGENCIA ag;

    agencia = fopen("agencias.dat", "rb");
    
    if (agencia == NULL) {
        printf("Erro ao abrir o arquivo de agencias.\n");
        return;
    }

    while (fread(&ag.codigo, sizeof(int), 1, agencia) == 1) {
        fread(ag.nome, sizeof(char), 50, agencia);
        fread(ag.gerente, sizeof(char), 50, agencia);
        printf("Codigo: %d, Nome: %s, Gerente: %s\n", ag.codigo, ag.nome, ag.gerente);
    }

    fclose(agencia);
}

void cadastrar_conta_corrente() {
    FILE *conta;
    CONTA_CORRENTE conta_corrente;

    conta = fopen("contas_correntes.dat", "ab");
    
    if (conta == NULL) {
        printf("Erro ao abrir o arquivo de contas correntes.\n");
        return;
    }

    printf("Digite o codigo da conta: ");
    scanf("%d", &conta_corrente.codigo);
    printf("Digite o codigo da agencia: ");
    scanf("%d", &conta_corrente.codigo_agencia);
    printf("Digite o saldo da conta: ");
    scanf("%lf", &conta_corrente.saldo);

    fwrite(&conta_corrente.codigo, sizeof(int), 1, conta);
    fwrite(&conta_corrente.codigo_agencia, sizeof(int), 1, conta);
    fwrite(&conta_corrente.saldo, sizeof(double), 1, conta);

    fclose(conta);
}

 void ler_contas_correntes() {
    FILE *conta;
    CONTA_CORRENTE conta_corrente;

    conta = fopen("contas_correntes.dat", "rb");
    
    if (conta == NULL) {
        printf("Erro ao abrir o arquivo de contas correntes.\n");
        return;
    }

    while (fread(&conta_corrente.codigo, sizeof(int), 1, conta) == 1) {
        fread(&conta_corrente.codigo_agencia, sizeof(int), 1, conta);
        fread(&conta_corrente.saldo, sizeof(double), 1, conta);
        printf("Codigo: %d, Codigo Agencia: %d, Saldo: %.2lf\n", conta_corrente.codigo, conta_corrente.codigo_agencia, conta_corrente.saldo);
    }

    fclose(conta);
}

int main(){


   int opcao;
   printf ("Programa iniciado!\n");
   printf("digite 1 para cadastrar agencias\n");
   printf("digite 2 para ler agencias\n");
   printf("digite 3 para cadastrar contas correntes\n");
   printf("digite 4 para ler contas correntes\n");
   printf("digite 5 para sair\n");
   scanf("%d", &opcao);

   switch (opcao) {
        case 1:
            cadastrar_agencia();
            break;
        case 2:
            ler_agencias();
            break;
        case 3:
            cadastrar_conta_corrente();
            break;
        case 4:
            ler_contas_correntes();
            break;
        case 5:
            exit(0);
        default:
            printf("Opção inválida!\n");
            break;
    }

    printf("Programa finalizado e dados gravados!\n");
    return 0;
}