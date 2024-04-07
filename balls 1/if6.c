#include <stdio.h>
//balls 101
int main() {
    float valor;
    printf("insira um valor\n");
    scanf("%f", &valor);
    if (valor > 100) {
        if (valor < 1000){
            printf("o valor esta entre 100 e 1000\n");
        } else {
            printf("o valor nao esta entre 100 e 1000");
        }
    } else {
        printf("o valor nao esta entre 100 e 1000\n");
    }
    return 0;
}