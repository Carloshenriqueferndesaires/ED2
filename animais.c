#include <stdio.h>
#include <string.h> 

int main() {
   
    char animais[20][50];
    int i;

    for(i = 0; i < 20; i++) {
        printf("Nome do animal %d: ", i + 1);
        scanf("%s", animais[i]); 
    }

    for(i = 0; i < 20; i++) {
        if(strlen(animais[i]) > 5) {
            printf("Animal com nome maior que 5 caracteres: %s\n", animais[i]);
        }
    }

    return 0;
}