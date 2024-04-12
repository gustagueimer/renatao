#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    int c = 111;
    printf("impressor de numeros pares entre 111 e 350 deluxe\n");
    while(c < 351) {
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