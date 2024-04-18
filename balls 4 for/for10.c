#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    char nomeAluno[20][10];
    char notaConceitualAluno[20][10];
    int matriculaAluno[10];
    int notaNominalFinal[10];
    for (int i = 1; i < 4; i++) {
        printf("i: %i\n", i);
        printf("insira nome do aluno - ");
        scanf("%s", &nomeAluno[i]);
        printf("insira a matricula do aluno - ");
        scanf("%i", &matriculaAluno[i]);
        printf("insira a nota nominal final do aluno (0 a 100) - ");
        scanf("%i", &notaNominalFinal[i]);
        switch (notaNominalFinal[i]) {
            case 0 ... 49: notaConceitualAluno[i-1][10] = 'D'; break;
            case 50 ... 69: notaConceitualAluno[i-1][10] = 'C'; break;
            case 70 ... 89: notaConceitualAluno[i-1][10] = 'B'; break;
            case 90 ... 100: notaConceitualAluno[i-1][10] = 'A'; break;        
        }
    }
    for (int i = 1; i < 4; i++) {
        printf("aluno: %s   matricula: %i   nota conceitual final: %s \n", nomeAluno[i], matriculaAluno[i], notaConceitualAluno[i]);
    }
    return 0;
}