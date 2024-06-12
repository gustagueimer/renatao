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
int comparer(int *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            for (int l=0;l<linhas;l++) {
                for (int c=0;c<colunas;c++) {
                    if (matrix[x * linhas + y] == matrix[l * linhas + c]) {
                        if ((x != l) || (y != c)) {
                            printf("Linha %i coluna %i (%i) é identico a linha %i coluna %i\n", x, y, matrix[x * linhas + y], l, c, matrix[l * linhas + c]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    int campoMinado[4][3] = {0};
    anbt();
    printf("comparador de existencia de elementos identicos na mesma matriz deluxe\n");
    printf("defina os valores da matriz:\n");
    getter(campoMinado, 4, 3);
    //debugging// printer(campoMinado, 4, 3);
    comparer(campoMinado, 4, 3);
    system("pause");
    return 0;
}