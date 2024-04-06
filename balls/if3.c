#include <stdio.h>
//balls 101
int main() {
    float valor;
    printf("insira uma valor\n");
    scanf("%f", &valor);
    if (valor > 50) {
        printf("o valor e maior que 50\n");
    } else {
        printf("o valor nao e maior que 50\n");
    }
    return 0;
}