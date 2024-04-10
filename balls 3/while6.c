#include <stdio.h>
#include <windows.h>
int main () {
    int c[2];
    c[1] = 600;
    c[2] = 0;
    printf("impressor de numeros deluxe\n");
    while(c[1] < 1001 ) {
        printf("numero atual: %i\n", c[1]);
        c[2] = c[2] + c[1];
        printf("soma total ate o momento: %i\n", c[2]);
        c[1]++;
    }
    system("pause");
    return 0;
}