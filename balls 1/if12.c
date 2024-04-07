#include <stdio.h>
//balls 101
int main() {

    int T;
    float l1;
    float l2;
    float l3;

    printf("insira o valor do primeiro lado\n");
    scanf("%f", &l1);

    printf("insira o valor do segundo lado\n");
    scanf("%f", &l2);

    printf("insira o valor do terceiro lado\n");
    scanf("%f", &l3);

    if (l1 <= (l2 + l3)) {
        if (l2 <= (l1 + l3)) {
            if (l3 <= (l1 + l2)) {
                T = 1;
            } else{
                printf("os lados nao podem formar um triangulo");
            }
        } else {
            printf("os lados nao podem formar um triangulo.");
        }
    } else {
        printf("os lados nao podem formar um triangulo");
    }

    if (T == 1) {
        if ((l1 == l2) && (l1 == l3)) {
            printf("triangulo equilatero\n");
        } else if ((l1 == l2) || (l1 == l3)) {
            printf("triangulo isosceles\n");
        } else if ((l2 == l1) || (l2 == l3)) {
            printf("triangulo isosceles\n");
        } else {
            printf("triangulo escaleno\n");
        }
    }
    return 0;
}