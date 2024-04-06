#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int dia;

    //input
    printf("insira um numero referente aos dias da semana (1-7)\n");
    scanf("%i", &dia);

    //processo e exibição de resultado
    switch (dia) {
        case 1: printf("dia da semana: domingao (do faustao)\n"); break;
        case 2: printf("dia da semana: segunda\n"); break;
        case 3: printf("dia da semana: terca\n"); break;
        case 4: printf("dia da semana: quarta\n"); break;
        case 5: printf("dia da semana: quinta\n"); break;
        case 6: printf("dia da semana: sextou\n"); break;
        case 7: printf("dia da semana: sabado\n"); break;
        default: printf("numero invalido\n");
    }
    system("pause");
    return 0;
}