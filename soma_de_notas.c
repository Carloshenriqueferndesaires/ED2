#include<stdio.h>

int main(){
   
    float notas[10];
    int i;

    for(i = 0; i < 10; i++){
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    float soma = 0.0;
    for(i = 0; i < 10; i++){
        soma += notas[i];
    }

    printf("A soma das notas eh: %.2f\n", soma );

    return 0;


}

