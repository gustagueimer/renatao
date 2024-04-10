#include <stdio.h>
#include <windows.h>
int main () {
    int c = 0;
    printf("impressor de numeros impares entre 0 e 2500 deluxe\n");
    while(c < 2500) {
        if (c % 2) {
            printf("%i\n", c);
            c++;
        } else {
            c++;
        }
    }
    system("pause");
    return 0;
}