#include <stdio.h>
//balls 101
int main() {
    int valor;
    printf("insira um valor\n");
    scanf("%i", &valor);
    if (valor % 2) {
        valor = valor * 3;
        printf("o valor e impar e o seu triplo e %i", valor);
    } else {
        valor = valor * 2;
        printf("o valor e par e o seu dobro e %i", valor);
    }
    return 0;
}