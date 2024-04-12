#include <stdio.h>
//balls 101
int main() {

    int i; 

    printf("insira sua idade\n");
    scanf("%i", &i);

    if ((i >= 5) && (i <= 7)) {
        printf("categoria: infantil A");
    } else if ((i >= 8) && (i <= 10)) {
        printf("categoria: infantil B");
    } else if ((i >= 11) && (i <= 13)) {
        printf("categoria: juvenil A");
    } else if ((i >= 14) && (i <= 17)){
        printf("categoria: juvenil B");
    }else if (i >= 18) {
        printf("categoria: adulto");
    }

    return 0;
}