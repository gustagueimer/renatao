#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int c = 1;
    int n = 3;
    printf("20 termos de 3 elevado a n\n");
    printf("1 termo: 0\n");
    while (c < 20) {
        c++;
        printf("%i termo: %d\n", c, n);
        n = n * 3;
    }
    system("pause");
    return 0;
}