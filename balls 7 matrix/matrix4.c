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
            printf("Linha %i coluna %i: %i\n", x, y, matrix[x * linhas + y]);
        }
        printf("-------//-------\n");
    }
    return 0;
}
int diagonalPrinter(int *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (y == x) {
                printf("Linha %i coluna %i: %i\n", x, y, matrix[x * linhas + y]);
            }
        }
    }
    return 0;
}
int main() {
    int dig[4][4] = {0};
    anbt();
    printf("criador de matrix e exibidor de seus valores localizados na diagonal deluxe\n");
    getter(dig, 4, 4);
    //debugging// printer(dig, 4, 4);
    diagonalPrinter(dig, 4, 4);
    system("pause");
    return 0;
}