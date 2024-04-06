#include <stdio.h>
#include <windows.h>
//balls 101
int main () {
        //definição de variavel
        int L [2];

        //input
        printf("digite o valor do comprimento\n");
        scanf("%i", &L[1]);
        printf("digite o valor da largura\n");
        scanf("%i", &L[2]);

        //processo e exibição do resultado (não dá/não faz sentido usar switch case)
        if (L[1] == L[2]) {
            printf("eh quadrado\n");
        } else {
            printf("eh retangulo\n");
        }
        system("pause");
}