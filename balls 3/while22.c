#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int q;
    int c = 1;
    int soma = 0;
    int soma2 = 0;
    printf("defina a quantidade de numeros a serem digitados - ");
    scanf("%i", &q);
    int t[q];
    while (c <= q) {
        printf("insira um numero - ");
        scanf("%i", &t[c]);
        if (t[c] > 10) {
            soma = soma + t[c];
        } else {
            soma2 = soma2 + 1;
        }
        c++;
    }
    printf("resultado da soma de numeros maiores que 10: %i\n", soma);
    printf("numero e numeros menores ou iguais a 10: %i\n", soma2);
    system("pause");
    return 0;
}