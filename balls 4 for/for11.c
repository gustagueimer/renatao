#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int n[2];
    float r[3];
    n[1] = 0;
    while (n[1] == 0) {
        printf("insira um valor inteiro, positivo e diferente de zero - ");
        scanf("%i", &n[2]);
        if (n[2] > 0) {
            n[1] = n[2];
            r[1] = 0;
            r[2] = 1;
            r[3] = 1;
        } else {
            printf("valor invalido\n");
        }
    }
    n[2] = 1;
    printf("%.4f + 1 = %.4f\n", r[1], r[2]);
    for (int i = 2; i <= n[1]; i++){
        r[1] = r[2];
        r[2] = r[1] + r[3]/i;
        printf("%.4f + 1/%i = %.4f\n", r[1], i, r[2]);

    }
    printf("resultado final: %.4f\n", r[2]);
    system("pause");
    return 0;
}