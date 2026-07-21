#include<stdio.h>
#include<string.h>

int main(){
    char cadeia1[30]="cavaleiro";
    char cadeia2[30]="dragao";
    printf("%s\n", cadeia1);
    strcpy(cadeia1, cadeia2);
    printf("%s\n", cadeia1);
    return 0;
}