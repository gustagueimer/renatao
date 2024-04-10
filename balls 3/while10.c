#include <stdio.h>
#include <windows.h>
int main () {
    int c[2];
    c[1] = 200;
    printf("impressor de uma media de numeros entre 200 a 350 deluxe\n");
    while(c[1] < 351) {
        c[2] = c[2] + c[1];
        c[1]++;
    }
    c[1] = c[2] / 150;
    printf("resultado final: %i\n", c[1]);
    system("pause");
    return 0;
}