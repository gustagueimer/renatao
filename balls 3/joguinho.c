#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//balls 101
int main () {
    int c [2];
    int n [2];
    c[2] = 0;
    n[2]=rand() % 3000;
    printf("hora do joguinho :D\n");
    while ((c[1] < 20)) {
        //debugzinho
        printf("n1: %i\n", n[1]);
        printf("n2: %i\n", n[2]);
        printf("c1: %i\n", c[1]);
        printf("c2: %i\n", c[2]);
        //joguinho, de fato.
        printf("digite um numero inteiro\n");
        scanf("%i", &n[2]);
        if (n[1]==n[2]) {
            c[2] = 1;
            c[1] = 20;
        } else if ((n[2]>n[1]) && (c[1]<19)) {
            printf("errou! (dica: e um numero menor)\n"); 
            c[1]++;
        } else if ((n[2]<n[1]) && (c[1]<19)) {
            printf("errou! (dica: e um numero maior)\n");
            c[1]++;
        } else {
            c[1]++;
        }
    }
    if (c[2] > 0) {
       printf("mlk e o albert einstein\n"); 
    } else {
       printf("muinto burro, da zero pra ele\n");
    }
    system("pause");
    return 0;
}