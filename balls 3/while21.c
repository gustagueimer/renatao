#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int n[2];
    n[2] = 0;
    printf("somador de numeros - digite 0 para ver o resultado\n");
    printf("insira um numero - ");
    scanf("%i", &n[1]);
    while (n[1] > 0) {
        n[2] = n[2] + n[1];
        printf("insira um numero - ");
        scanf("%i", &n[1]);
    }
    printf("resultado da soma: %i\n", n[2]);
    system("pause");
    return 0;
}