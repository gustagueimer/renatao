#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    int c = 3000;
    printf("impressor de numeros decrescentes deluxe\n");
    while(c > 99) {
        printf("%i\n", c);
        c--;
    }
    system("pause");
    return 0;
}