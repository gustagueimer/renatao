#include <stdio.h>
#include <windows.h>
#define LINES 4
#define ROWS 5
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("informe um elemento da tabela numérica - ", x, y);
            scanf("%i", &matrix[x][y]);
        }
    }
    return 0;
}
int printer(int matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("%i ", matrix[x][y]);
        }
        printf("\n");
    }
    printf("----//----\n");
    return 0;
}
int transposer(int matriz[LINES][ROWS], int linhas, int colunas) {
    int transpost[colunas][linhas];
    for (int x=0;x<colunas;x++) {
        for (int y=0;y<linhas;y++) {
            transpost[x][y] = 0;
        }
    }
    printf("matriz original:\n");
    printer(matriz, linhas, colunas);
    
    int tX = 0, tY = 0;
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            transpost[tX][tY] = matriz[x][y];
            // debugging// printf("matriz[%i][%i]: %i trasposer[%i][%i]: %i\n", x, y, matriz[x][y], tX, tY, transpost[tX][tY]);
            tX++;
        }
        tY++;
        tX = 0;
    }
    printf("matriz transposta:\n");;
    for (int x=0;x<colunas;x++) {
        for (int y=0;y<linhas;y++) {
            printf("%i ", transpost[x][y]);
        }
        printf("\n");
    }
    printf("----//----\n");
    return 0;
}
int main() {
    int balls[LINES][ROWS] = {0};
    anbt();
    printf("tranpostador de matriz deluxe UHD\n");
    printf("insira os valores da matriz:\n");
    getter(balls, LINES, ROWS);
    transposer(balls, LINES, ROWS);
    system("pause");
    return 0;
}