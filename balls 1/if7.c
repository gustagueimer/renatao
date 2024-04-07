#include <stdio.h>
//balls 101
int main() {
    int valor;
    printf("insira um valor\n");
    scanf("%i", &valor);
    if (valor % 2) {
        printf("o valor e impar\n");
    } else {
        printf("o valor e par\n");
    }
    return 0;
}