#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    int x;
    int c[2];
    printf("impressor de fatorial deluxe\n");
    printf("insira um valor\n");
    scanf("%i", &x);
    c[1] = x;
    c[2] = x;
    while(c[1] > 1) {
        c[1]--;
        printf("etapa: %i x %i: ", c[2], c[1]);
        c[2] = c[2] * c[1];
        printf("%i\n", c[2]);
    }
    printf("resultado final: %i\n", c[2]);
    system("pause");
    return 0;
}