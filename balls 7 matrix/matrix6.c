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
int getRekt(int *matrix, int linhas, int colunas) {
    int somatória=0;
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if ((x == y) && (matrix[x * linhas + y] % 2 == 0)) {
                somatória = somatória + matrix[x * linhas +y];   
            }
        }
    }
    printf("somatória dos elementos pares na diagonal da matriz: %i\n", somatória);
    return 0;
}
int main() {
    int flextape[15][15] = {0};
    anbt();
    printf("criador de tabela e mostrador a soma dos elementos pares na diagonal dessa tabela deluxe");
    printf("insira os valores da tabela:\n");
    getter(flextape, 4, 4);
    //debugging// printer(flextape, 4, 4);
    getRekt(flextape, 4, 4);
    system("pause");
    return 0;    
}