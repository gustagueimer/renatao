#include <stdio.h>
#include <windows.h>
#define LINES 4
#define ROWS 4
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int matrix[LINES], int linhas) {
    for (int x=0;x<linhas;x++) {
            printf("informe um elemento da tabela numérica - ");
            scanf("%i", &matrix[x]);
    }
    return 0;
}
int printerVetor(int vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int printerMatrix(double matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("%.f ", matrix[x][y]);
        }
        printf("\n");
    }
    printf("----//----\n");
    return 0;
}
double factorial(double a) {
    double result = 1;
    for (int i=2;i<=a;i++) {
        result = result * i;
    }
    return result;
}
int vectorConvector(int vetorA[], int vetorB[], int vetorC[], int vetorD[], int tamanho) {
    double notMatrixMultiplier[tamanho][tamanho];
    for (int x=0;x<tamanho;x++) {
        for (int y=0;y<tamanho;y++) {
            notMatrixMultiplier[x][y] = 0;
        }
    }
    for (int x=0;x<tamanho;x++) {
        for (int y=0;y<tamanho;y++) {
            switch(x) {
                case 0: notMatrixMultiplier[x][y] = vetorA[y] * 2; break;
                case 1: notMatrixMultiplier[x][y] = vetorB[y] * 3; break;
                case 2: notMatrixMultiplier[x][y] = vetorC[y] * 4; break;
                case 3: notMatrixMultiplier[x][y] = factorial((double)vetorD[y]); break;
            }
        }
    }
    printerMatrix(notMatrixMultiplier, tamanho, tamanho);
    return 0;
}
int main() {
    anbt();
    int vA[LINES] = {0},
        vB[LINES] = {0},
        vC[LINES] = {0},
        vD[LINES] = {0};
    getter(vA, LINES);
    printerVetor(vA, LINES);
    getter(vB, LINES);
    printerVetor(vB, LINES);
    getter(vC, LINES);
    printerVetor(vC, LINES);
    getter(vD, LINES);
    printerVetor(vD, LINES);
    vectorConvector(vA, vB, vC, vD, LINES);
    system("pause");
}