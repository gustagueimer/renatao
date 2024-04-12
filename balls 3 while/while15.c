#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int c[2];
    int nota1[3], nota2[3], nota3[3], nota4[4], nota5[3];
    char aluno[6][20];
    c[1]= 0;
    c[2]= 0;
    printf("leitor de nomes, notas e calculador de medias deluxe\n");
    while (c[1] < 5) {
        c[1]++;
        printf("insira o nome do aluno %i - ", c[1]);
        scanf("%s", &aluno[c[1]]);
            switch (c[1]) {
            case 1: printf("insira as tres notas do aluno\n"); scanf("%i %i %i", &nota1[1], &nota1[2], &nota1[3]); nota1[1] = (nota1[1] + nota1[2] + nota1[3]) / 3; break;
            case 2: printf("insira as tres notas do aluno\n"); scanf("%i %i %i", &nota2[1], &nota2[2], &nota2[3]); nota2[1] = (nota2[1] + nota2[2] + nota2[3]) / 3; break;
            case 3: printf("insira as tres notas do aluno\n"); scanf("%i %i %i", &nota3[1], &nota3[2], &nota3[3]); nota3[1] = (nota3[1] + nota3[2] + nota3[3]) / 3; break;
            case 4: printf("insira as tres notas do aluno\n"); scanf("%i %i %i", &nota4[1], &nota4[2], &nota4[3]); nota4[1] = (nota4[1] + nota4[2] + nota4[3]) / 3; break;
            default: printf("insira as tres notas do aluno\n"); scanf("%i %i %i", &nota5[1], &nota5[2], &nota5[3]); nota5[1] = (nota5[1] + nota5[2] + nota5[3]) / 3; break;
        }
    }
    c[1] = 0;
        while (c[1] < 5) {
        c[1]++;
        printf("nome: %s - ", aluno[c[1]]);
        switch (c[1]) {
            case 1: printf("media: %i\n", nota1[1]); break;
            case 2: printf("media: %i\n", nota2[2]); break;
            case 3: printf("media: %i\n", nota3[1]); break;
            case 4: printf("media: %i\n", nota4[1]); break;
            default: printf("media: %i\n", nota5[1]); break;
        }
    }
    system("pause");
    return 0;
}