#include <stdio.h>
#include <windows.h>
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
int printer(int *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("Linha %i coluna %i: %i\n", x+1, y+1, matrix[x * linhas + y]);
        }
        printf("-------//-------\n");
    }
    return 0;
}
int iGotNoTime(int *matriz, int linhas, int colunas) {
    int l4soma = 0;
    int c2soma = 0;
    int diagonalSoma = 0;
    int allSoma =0;
    int batlepass[linhas][colunas];
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (x == 3) {
                l4soma = l4soma + matriz[x * linhas + y];
                printf("somou: l4+ = %i\n", l4soma);
            }
            if (y == 1) {
                c2soma = c2soma + matriz[x * linhas + y];
                printf("somou: c2+ = %i\n", c2soma);
            }
            if (x == y) {
                diagonalSoma = diagonalSoma + matriz[x * linhas + y];
            }
            allSoma = allSoma + matriz[x * linhas + y];
        }
    }
    printf("matriz original:\n");
    printer(matriz, linhas, colunas);
    printf("soma dos elementos da quarta linha: %i\n", l4soma);
    printf("soma dos elementos da segunda coluna: %i\n", c2soma);
    printf("soma dos elementos na diagonal: %i\n", diagonalSoma);
    printf("soma de todos os elementos: %i\n", allSoma);
    return 0;
}
int main() {
    int theBookOnTheTable[5][5] = {0};
    anbt();
    printf("criador de matriz e realizador de diversas somas deluxe\n");
    printf("insira os valores da primeira tabela\n");
    getter(theBookOnTheTable, 5, 5);
    iGotNoTime(theBookOnTheTable, 5, 5);
    system("pause");
    return 0;
}