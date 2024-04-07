#include <stdio.h>
//balls 101
int main() {

    float n1; 
    float n2;

    printf("insira um numero\n");
    scanf("%f", &n2);

    printf("insira outro numero\n");
    scanf("%f", &n1);

    if (n1 <= n2) {
        n1 = n2 - n1;
    } else if (n2 <= n1) {
        n1 = n1 - n2;
    }

    printf("resultado: %f", n1);
    return 0;
}