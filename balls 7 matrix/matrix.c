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
int matrixMultiplier(int *matrix, int linhas, int colunas, int multiplicador) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            matrix[x * linhas + y] = matrix[x * linhas + y] * multiplicador;
        }
    }
    return 0;
}
int main() {
    anbt();
    int arrayyy[6][6] = {0};
    int multiplier=0;
    printf("pegador de matrix 6x6 e multiplicador por valor definido pelo usuário deluxe\n");
    printf("defina os elementos do array:\n");
    getter(arrayyy, 6, 6);
    printf("digite o numero a qual a matriz será multiplicada:\n");
    scanf("%i", &multiplier);
    matrixMultiplier(arrayyy, 6, 6, multiplier);
    printer(arrayyy, 6, 6);
    system("pause");
    return 0;
}