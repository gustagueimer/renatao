#include <stdio.h>
//balls 101
int main() {

    float nota1;
    int nota2;
    int nota3;

    printf("insira uma nota\n");
    scanf("%f", &nota1);

    printf("insira uma nota\n");
    scanf("%i", &nota2);

    printf("insira uma nota\n");
    scanf("%i", &nota3);

    nota1 = (nota1 + nota2 + nota3) / 3;

    if (nota1 < 4.0) {
        printf("media: %f; resultado: reprovado", nota1);
    } else {
        if (nota1 >= 7.0) {
            printf("media: %f; resultado: aprovado", nota1);
        } else {
            printf("media: %f; resultado: exame", nota1);
        }
    }
    return 0;
}