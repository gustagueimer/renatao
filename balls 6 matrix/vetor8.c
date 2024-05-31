#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[]) {
    for (int i=0;i<5;i++) {
        printf("informe um elemento da tabela numérica - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int fuser(int table1[], int table2[], int table3[]) {
    int vD[15] = {0};
    for (int i=0;i<5;i++) {
        vD[i] = table1[i];
    }
    for (int i=5;i<10;i++) {
        vD[i] = table2[i-5];
    }
    for (int i=10;i<15;i++) {
        vD[i] = table3[i-10];
    }
    printf("valores da primeira table:\n");
    printer(table1, 5);
    printf("valores da segunda table:\n");
    printer(table2, 5);
    printf("valores da terceira table:\n");
    printer(table3, 5);
    printf("table final:\n");
    printer(vD, 15);
    return 0;
}
int printer(int vetor[], int a) {
    for (int i=0;i<a;i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int vA[5] = {0};
    int vB[5] = {0};
    int vC[5] = {0};
    anbt();
    printf("pegador de três tabelas e fundidor em uma só deluxe\n");
    printf("insira os valores da primeira tabela:\n");
    getter(&vA);
    printf("insira os valores da segunda tabela:\n");
    getter(&vB);
    printf("insira os valores da terceira tabela:\n");
    getter(&vC);
    fuser(vA, vB, vC);
    system("pause");
    return 0;
}