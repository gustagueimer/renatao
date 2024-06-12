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
double factorial(double a) {
    double result = 1;
    for (int i=2;i<=a;i++) {
        result = result * i;
    }
    return result;
}
int fatoriador(int *matriz, int linhas, int colunas) {
    double fatorial[linhas][colunas];
    printf("matriz fatorada:\n");
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            fatorial[x][y] = matriz[x * linhas + y];
            fatorial[x][y] = factorial(fatorial[x][y]);
            printf("transposer[%i][%i] = %.f\n", x, y, fatorial[x][y]);
        }
    }
    return 0;
}
int main() {
    int normal[5][4] = {0};
    anbt();
    printf("criador de matriz e criador de matriz com fatorial em cada elemento deluxe\n");
    printf("insira os valores da primeira matriz:\n");
    getter(normal, 5, 4);
    printf("tabela original:\n");
    printer(normal, 5, 4);
    fatoriador(normal, 5, 4);
    system("pause");
    return 0;
}