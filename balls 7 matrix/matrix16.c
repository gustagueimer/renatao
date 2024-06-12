#include <stdio.h>
#include <windows.h>
#define LINES 4
#define ROWS 5
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("informe um elemento da tabela numérica - ");
            scanf("%i", &matrix[x][y]);
        }
    }
    return 0;
}
int printerVetor(int vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int printerMatrix(int matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("%i ", matrix[x][y]);
        }
        printf("\n");
    }
    printf("----//----\n");
    return 0;
}
int jooj(int matriz[LINES][ROWS], int linhas, int colunas) {
    int vector[linhas];
    for (int x=0;x<linhas;x++) {
        vector[x] = 0; 
    }
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            vector[x] += matriz[x][y];
        }
    }
    printf("vetor:\n");
    printerVetor(vector, linhas);
    return 0;
}
int main() {
    int test[LINES][ROWS] = {0};
    anbt();
    printf("compilador de vetor sendo a soma de linhas de uma matriz ultra deluxe\n");
    printf("insira valores:\n");
    getter(test, LINES, ROWS);
    printf("matriz original:\n");
    printerMatrix(test, LINES, ROWS);
    jooj(test, LINES, ROWS);
    system("pause");
    return 0;
}