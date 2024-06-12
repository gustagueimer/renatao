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
int parPrinter(int *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (matrix[x * linhas + y] % 2 == 0) {
                printf("Linha %i coluna %i (%i) é par\n", x, y, matrix[x * linhas + y]);
            }
        }
    }
    return 0;
}
int main() {
    int matrix[2][5] = {0};
    anbt();
    printf("pegador de matrix e procurador de numeros pares nela deluxe\n");
    getter(matrix, 2, 5);
    //debugging// printer(matrix, 2, 5);
    parPrinter(matrix, 2, 5);
    system("pause");
    return 0;
}