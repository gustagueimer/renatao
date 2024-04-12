#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    float c[2];
    c[1] = 200;
    c[2] = 0;
    printf("impressor de uma media de numeros entre 200 a 350 deluxe\n");
    while(c[1] <=350) {
        c[2] = c[2] + c[1];
        c[1]++;
    }
    c[1] = c[2] / 151;
    printf("resultado final: %.2f\n", c[1]);
    system("pause");
    return 0;
}