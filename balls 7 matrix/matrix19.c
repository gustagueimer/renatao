#include <stdio.h>
#include <windows.h>
#define LINES 1
#define ROWS 12
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("informe um elemento da tabela numérica - ");
            scanf("%i", &matrix[x * linhas + y]);
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
int fuser(int *vetor1, int *vetor2, int linhas, int colunas) {
    int linhasM = linhas *2;
    int matriz[linhasM][colunas];
    for (int x=0;x<linhas*2;x++) {
        for (int y=0;y<colunas;y++) {
            if (x == 0) {
                matriz[x][y] = vetor1[y] * 2;
            } else {
                matriz[x][y] = vetor2[y] - 5;
            }
        }
    }
    printf("vetor 1:\n");
    printerVetor(vetor1,  colunas);
    printf("vetor 2:\n");
    printerVetor(vetor2, colunas);
    printf("matriz:\n");
    printerMatrix(matriz, linhasM, colunas);
    return 0;
}
int main() {
    int v1[LINES][ROWS] = {0};
    int v2[LINES][ROWS] = {0};
    anbt();
    printf("pegador de dois vetores e juntador em uma matrix deluxe\n");
    printf("insira os valores do primeiro vetor:\n");
    getter(v1, LINES, ROWS);
    printf("insira os valores do segundo vetor:\n");
    getter(v2, LINES, ROWS);
    fuser(v1, v2, LINES, ROWS);
    system("pause");
    return 0;
}