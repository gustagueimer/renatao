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
int psor(int *matriz, int linhas, int colunas) {
    int somator = 0;
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if ((x == y) && (x+1 % 2 != 0)) {
                somator = somator + matriz[x * linhas + y];
            }
        }
    }
    printf("soma dos elementos das linhas e colunas impares na diagonal da matrix: %i\n", somator);
    return 0;
}
int main() {
    int renatão[5][5] = {0};
    anbt();
    printf("criador de tabela e somador das linhas e colunas impares na diagonal deluxe 3D\n");
    printf("defina os valores da matriz:\n");
    getter(renatão, 5, 5);
    //debugging// printer(renatão, 5, 5);
    psor(renatão, 5, 5);
    system("pause");
    return 0;
}