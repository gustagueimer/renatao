#include <stdio.h>
#include <windows.h>


int main () {
    char R = 't';
    int R2;
    int L [3];
    int T [10];
    int tc;
    while (L[3] != 1) {
        R2 = 1;
        L[3] = 0;
        printf("digite o valor do comprimento\n");
        scanf("%i", &L[1]);
        printf("digite o valor da largura\n");
        scanf("%i", &L[2]);
        if (L[1] == L[2]) {
            printf("eh quadrado\n");
        } else {
            printf("eh retangulo\n");
        }
        system("pause");
        while (R2 != 0) {
            printf("repetir? y/n\n");
            scanf("%s", &R);
            switch (R) {            
                case 'y':
                    R2 = 0;
                    printf("blz ent\n");
                    printf("---------------------------------------------------------------------------------\n");
                    break;
                case 'n':
                    R2 = 0;
                    L[3] = 1; 
                    break;
                default:
                    R2 = 1;
                    printf("opcao invalida\n");
                    printf(" \n");
            } 
        } 
    } 
    tc = 1;
    while (tc < 11) {
        printf("insira um valor\n");
        scanf("%i", &T[tc]);
        tc = tc + 1;
    }
    tc = 1;
    while (tc < 11) {
        printf("T%i: %i\n", tc, T[tc]);
        tc = tc + 1;
    }
    system("pause");
    return 0;
}
