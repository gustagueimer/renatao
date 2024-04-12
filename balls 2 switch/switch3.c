#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int data [3];

    //input
    printf("insira um dia\n");
    scanf("%i", &data[1]);
    printf("insira um mes\n");
    scanf("%i", &data[2]);
    printf("insira um ano (entre 1900 e 2100)\n");
    scanf("%i", &data[3]);
    
    //verificação da data e exibição do resultado
    if ((data[1] < 0) || (data[1] > 31)) {
        printf("data invalida\n");
    } else if ((data[2] < 1) || (data[2] > 12)) {
        printf("data invalida\n");
    } else if ((data[3] < 1900) || (data[3] > 2100)) {
        printf("data invalida\n");
    } else { 
        printf("%i/%i/%i\n", data[1], data[2], data[3]);
    }
    if (data[1] != data[2]) {
        printf("o dia e o mês não são iguais\n");
    } else {
        switch (data[1]) {
            case 1: printf("a data e o 1 dia do ano\n"); break;
            case 2: printf("a data e o 33 dia do ano\n"); break;
            case 3: printf("a data e o 62 dia do ano\n"); break;
            case 4: printf("a data e o 94 dia do ano\n"); break;
            case 5: printf("a data e o 125 dia do ano\n"); break;
            case 6: printf("a data e o 157 dia do ano\n"); break;
            case 7: printf("a data e o 188 dia do ano\n"); break;
            case 8: printf("a data e o 220 dia do ano\n"); break;
            case 9: printf("a data e o 252 dia do ano\n"); break;
            case 10: printf("a data e o 283 dia do ano\n"); break;
            case 11: printf("a data e o 315 dia do ano\n"); break;
            case 12: printf("a data e o 346 dia do ano\n"); break;
        }
    }

    //finalização
    system("pause");
    return 0;
}