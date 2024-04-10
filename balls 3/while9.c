#include <stdio.h>
#include <windows.h>
int main () {
    int c[2];
    c[1] = 5;
    printf("impressor de uma media de numeros entre 5 a 150 deluxe\n");
    while(c[1] < 151) {
        c[2] = c[2] + c[1];
        c[1]++;
    }
    c[1] = c[2] / 145;
    printf("resultado final: %i\n", c[1]);
    system("pause");
    return 0;
}