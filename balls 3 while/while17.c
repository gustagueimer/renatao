#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
    int q;
    printf("defina quantos numeros serao digitados - ");
    scanf("%d", &q);
    int t[q];
    int c = 1;
    while (c <= q) {
        printf("insira numero - ");
        scanf("%i", &t[c]);
        c++;
    }
    c = 1;
    printf("numeros pares: \n");
    while (c <= q) {
        if (t[c] % 2) {
            c++;
        } else {
            printf("%i \n", t[c]);
            c++;
        } 
    }
    system("pause");
    return 0;
}