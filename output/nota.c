#include<stdio.h>
int main()
{
    int quantidade = 0;
    float nota=0.0, soma=0.0;
    while(nota >= 0.0)
    {
        scanf("%f", &nota);
        if(nota >= 0)
        {
            soma = soma + nota;
            quantidade = quantidade + 1;
        }
    }
    printf("A media eh: %f\n", soma/quantidade);
    return 0;
}