#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int q;
    int c = 1;
    int soma = 0;
    printf("defina a quantidade de numeros a serem digitados - ");
    scanf("%i", &q);
    int t[q];
    while (c <= q) {
        printf("insira um numero - ");
        scanf("%i", &t[c]);
        if (t[c] > 5) {
            soma = soma + t[c];
        } 
        c++;
    }
    printf("resultado da soma: %i", soma);
    system("pause");
    return 0;
}