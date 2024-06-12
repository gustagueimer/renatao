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
int noTime(int *matriz, int linhas, int colunas) {
    int ed[linhas][colunas];
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (matriz[x * linhas + y] % 2 == 0) {
                ed[x][y] = matriz[x * linhas + y] + 5;
            } else {
                ed[x][y] = matriz[x * linhas + y] - 4;
            }
        }
    }
    printf("matriz original:\n");
    printer(matriz, linhas, colunas);
    printf("matriz nova:\n");
    printer(ed, linhas, colunas);
    return 0;
}
int main() {
    int timdodd[6][5] = {0};
    anbt();
    printf("sem tempo pra explicar deluxe\n");
    printf("insira os valores da matriz:\n");
    getter(timdodd, 6, 5);
    noTime(timdodd, 6, 5);
    system("pause");
    return 0;
}