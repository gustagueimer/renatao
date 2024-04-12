#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    int c = 30;
    printf("impressor de numeros impares entre 29 e 1 deluxe\n");
    while(c != 0) {
        if (c % 2) {
            printf("%i\n", c);
            c--;
        } else {
            c--;
        }
    }
    system("pause");
    return 0;
}