#include <stdio.h>
#include <windows.h>
int main () {
    int c = 50;
    printf("impressor de numeros deluxe\n");
    while(c < 251) {
        printf("%i\n", c);
        c++;
    }
    system("pause");
    return 0;
}