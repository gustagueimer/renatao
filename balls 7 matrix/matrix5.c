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
int matrizSoma(int *matriz1, int *matriz2,int linhas, int colunas) {
    int matriz3[linhas][colunas];
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            matriz3[x][y] = matriz1[x * linhas + y] + matriz2[x * linhas + y];
        }
    }
    printf("valores da matriz 3 (soma):\n");
    printer(matriz3, linhas, colunas);
    return 0;
}
int matrizSubtracao(int *matriz1, int *matriz2, int linhas, int colunas) {
    int matriz4[linhas][colunas];
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            matriz4[x][y] = matriz1[x * linhas + y] - matriz2[x * linhas + y];
        }
    }
    printf("valores da matriz 4 (subtração):\n");
    printer(matriz4, linhas, colunas);
    return 0;
}
int main() {
    int matriz1[4][6] = {0};
    int matriz2[4][6] = {0};
    anbt();
    printf("criador de duas matrizes e criador de mais duas matrizes\ncom base na soma e diferença entre as duas primeiras deluxe\n");
    printf("insira os valores da primera matriz:\n");
    getter(matriz1, 4, 6);
    printf("insira os valores da segunda tabela:\n");
    getter(matriz2, 4, 6);
    printf("valores da matriz 1:\n");
    printer(matriz1, 4, 6);
    printf("valores da matriz 2:\n");
    printer(matriz2, 4, 6);
    matrizSoma(matriz1, matriz2, 4, 6);
    matrizSubtracao(matriz1, matriz2, 4, 6);
    system("pause");
    return 0;
}