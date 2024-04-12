#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    int c = 0;
    printf("impressor de numeros pares entre 1 a 30 deluxe\n");
    while(c < 31) {
        if (c % 2) {
            c++;
        } else {
            printf("%i\n", c);
            c++;
        }
    }
    system("pause");
    return 0;
}