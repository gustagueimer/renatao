#include <stdio.h>
//balls 101
int main() {

    int n1;
    int n2; 

    printf("insira um numero\n");
    scanf("%i", &n1);

    printf("insira outro numero\n");
    scanf("%i", &n2);

    if (n1 % n2) {
        if (n2 % n1) {
            printf("nao sao multiplos.");
        } else {
            printf("sao multiplos.");
        }
    } else {
        printf("nao sao multiplos");
    }
    return 0;
}