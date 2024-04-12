#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int c = 1;
    float nota[3];
    char aluno[20];
    printf("leitor de nome, notas e calculador de media deluxe\n");
    while (c > 0) {
        printf("--------------------------------------------------------------------------------------\n");
        printf("insira o nome do aluno - ");
        scanf("%s", &aluno);
        printf("insira as tres notas do aluno\n"); 
        scanf("%f %f %f", &nota[1], &nota[2], &nota[3]); 
        nota[1] = (nota[1] + nota[2] + nota[3]) / 3;
        printf("aluno: %s - media: %.2f\n", aluno, nota[1]);
        system("pause");
        printf("deseja repetir?\n");
        printf("sim-1 nao-0\n");
        scanf("%i", &c);
    }
    return 0;
}