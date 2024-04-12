#include <stdio.h>
//balls 101
int main() {

    int n1;
    int n2;
    int n3;

    printf("insira um numero\n");
    scanf("%i", &n1);

    printf("insira outro numero\n");
    scanf("%i", &n2);

    printf("insira mais um numero\n");
    scanf("%i", &n3);

    if (n1 < n2) {
        if (n1 < n3) {
            if (n2 < n3) {
                printf("ordem crescente:%i %i %i", n1, n2, n3);
            } else if (n3 < n2) {
                printf("ordem crescente:%i %i %i", n1, n3, n2);
            }
        }
    } 

    if (n2 < n1) {
        if (n2 < n3) {
            if (n1 < n3) {
                printf("ordem crescente:%i %i %i", n2, n1, n3);
            } else if (n3 < n1) {
                printf("ordem crescente:%i %i %i", n2, n3, n1);
            }
        }
    } 

    if (n3 < n1) {
        if (n3 < n2) {
            if (n1 < n2) {
                printf("ordem crescente:%i %i %i", n3, n1, n2);
            } else if (n2 < n1) {
                printf("ordem crescente:%i %i %i", n3, n2, n1);
            }
        }
    } 

    return 0;
}