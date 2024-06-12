#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(float *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("informe um elemento da tabela numérica - ");
            scanf("%f", &matrix[x * linhas + y]);
        }
    }
    return 0;
}
int printer(float *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("Linha %i coluna %i: %.2f\n", x+1, y+1, matrix[x * linhas + y]);
        }
        printf("-------//-------\n");
    }
    return 0;
}
int iCant(float *matriz, int linhas, int colunas) {
    int maior=0;
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (matriz[x * linhas + y] > maior) {
                maior = matriz[x * linhas + y];
            }
        }
    }
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            matriz[x * linhas + y] = matriz[x * linhas + y] / maior;
        }
    }
    printf("matriz dividida pelo maior elemento:\n");
    printer(matriz, linhas, colunas);
    return 0;
}
int main() {
    float matriz[6][3] = {0};
    anbt();
    printf("eu realmente estou sem tempo pra explicar deluxe\n");
    printf("insira os valores da matriz:\n");
    getter(matriz, 6, 3);
    printf("matriz original:\n");
    printer(matriz, 6, 3);
    iCant(matriz, 6, 3);
    system("pause");
    return 0;
}