#include <stdio.h>
#include <windows.h>

int main(){
    int c;
    char nome[3][20];
    c = 0;
    printf("leitor e impressor de nomes deluxe\n");
    while (c < 3) {
        c++;
        printf("c: %i", c);
        printf("insira um nome - ");
        scanf("%s", nome[c]);
    }
    c = 0;
    printf("nomes digitados: \n");
    while (c < 3) {
        c++;
        switch (c) {
            case 1: printf("primeiro nome: %s\n", nome[1]); break;
            case 2: printf("segundo nome: %s\n", nome[2]); break;
            default: printf("terceiro nome: %s\n", nome[3]); break;
        }    
    }
    system("pause");
    return 0;
}