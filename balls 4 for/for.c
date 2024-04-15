#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int q;
    printf("insira um numero - ");
    scanf("%i", &q);
    for (int i; i <= q; i++) {
    printf("%i\n", i);
    }
    system("pause");
    return 0;
}