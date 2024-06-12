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
int muitoTrampo(int *matriz, int linhas, int colunas) {
    int batlepass[linhas][colunas];
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (x == y) {
                batlepass[x][y] = matriz[x * linhas + y] * 3;
            } else {
                batlepass[x][y] = matriz[x * linhas + y] * 2;
            }
        }
    }
    printf("matriz em dobro (e em triplo também):\n");
    printer(batlepass, linhas, colunas);
    return 0;
}
int main() {
    int fornai[5][5] = {0};
    anbt();
    printf("criador de matriz e criador de outra matriz com base na primeira\nonde tudo é em dobro exceto pelos elementos em diagonal pq eles\nsão em triplo deluxe remake\n");
    printf("insira os valores da primeira matriz:\n");
    getter(fornai, 5, 5);
    muitoTrampo(fornai, 5, 5);
    system("pause");
    return 0;
}