#include <stdio.h>
//balls 101
int main() {
    float valor;
    printf("insira uma valor\n");
    scanf("%f", &valor);
    if (valor > 0) {
        if (valor< 51) {
        printf("o valor esta entre 1 e 50\n");
        } else {
        printf("o valor nao esta entre 1 e 50\n");
        }
    } else {
        printf("o valor nao esta entre 1 e 50\n");
    }
    return 0;
}