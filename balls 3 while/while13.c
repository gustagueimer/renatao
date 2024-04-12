#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    float c[4];
    printf("impressor de uma media de numeros entre uma faixa definida pelo usuario deluxe\n");
    printf("insira o numero de inicio\n");
    scanf("%f", &c[1]);
    c[2] = 0;
    c[4] = c[1];
    printf("insira o numero de final\n");
    scanf("%f", &c[3]);
    while(c[1] <= c[3]) {
        c[2] = c[2] + c[1];
        printf("c1: %.2f\n", c[1]);
        printf("c2: %.2f\n", c[2]);
        c[1]++;
    }
    printf("c1: %.2f\n", c[1]);
    printf("c2: %.2f\n", c[2]);
    printf("c3: %.2f\n", c[3]);
    printf("c4: %.2f\n", c[4]);
    c[1] = c[2] / ((c[3] - c[4]) + 1);
    printf("resultado final: %.2f\n", c[1]);
    system("pause");
    return 0;
}