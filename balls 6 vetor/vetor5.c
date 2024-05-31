#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
double factorial(double a) {
    double result = 1;
    for (int i=2;i<=a;i++) {
        result = result * i;
    }
    return result;
}
int getter(int vetor[]) {
    for (int i=0;i<15;i++) {
        printf("type a (positive) number - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int fatorMacho(int vetor[]) {
    double tabelao2[15] = {0};
    for (int i=0;i<15;i++) {
        tabelao2[i] = (double)vetor[i];
        tabelao2[i] = factorial(tabelao2[i]);
    } 
    printf("tabela original:\n");
    printer(vetor);
    printf("tabela fatorada:\n");
    printerD(tabelao2);
    return 0;
}
int printer(int vetor[]) {
    for (int i=0;i<15;i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int printerD(double vetor[]) {
    for (int i=0;i<15;i++) {
        printf("%i° numero: %.f\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int tabelao[15] = {0};
    anbt();
    printf("pegador de tabela e criador de outra tabela com o\nresultado fatorial com base na primeira tabela deluxe\n");
    getter(&tabelao);
    fatorMacho(tabelao);
    system("pause");
    return 0;
}