#include <stdio.h>
#include <windows.h>
int main () {
    int c[2];
    c[1] = 6;
    c[2] = 6;
    printf("impressor de fatorial de 6 deluxe\n");
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