#include <stdio.h>
//balls 101
int main() {
    float valor;
    printf("insira uma valor\n");
    scanf("%f", &valor);
    if (valor > 0) {
        printf("o valor e positivo.\n");
    } else {
        if (valor < 0) {
           printf("o valor e negativo.\n");
        } else {
           printf("o valor e zero.\n");
        }
    }
    return 0;
}