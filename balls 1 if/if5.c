#include <stdio.h>
//balls 101
int main() {
    int valor;
    printf("insira um valor\n");
    scanf("%i", &valor);
    if (valor % 5) {
        printf("o valor nao e multiplo de 5\n");
    } else {
        printf("o valor e multiplo de 5\n");
    }
    return 0;
}