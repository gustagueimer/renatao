#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int r;
    float n [3];
    float media;

    //input
    printf("insira nota\n");
    scanf("%f", &n[1]);
    printf("insira nota\n");
    scanf("%f", &n[2]);
    printf("insira nota\n");
    scanf("%f", &n[3]);

    //debug
    printf("%f  %f  %f\n", n[1], n[2], n[3]);

    //process
    media = (n[1] + n[2] + n[3]) / 3;
    
    //debug
    printf("%f\n", media);
 
    //processo
    if (media >= 7) {
        r = 1;
    } else {
        r = 0;
    }
 
    //seleção e exibição do resultado
    switch (r) {
        case 1:
            printf("aluno aprovado\n");
            break;
        default:
            printf("aluno ficou pro exame\n");
            media = 7 - media;
            printf("nota nescessaria no exame para o aluno ser aprovado: %f\n", media);
    }
    system("pause");

    return 0;
}