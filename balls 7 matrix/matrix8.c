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
            printf("informe uma temperatura em °C - ");
            scanf("%f", &matrix[x * linhas + y]);
        }
    }
    return 0;
}
int printer(float *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("Linha %i coluna %i: %.2f\n", x, y, matrix[x * linhas + y]);
        }
        printf("-------//-------\n");
    }
    return 0;
}
int fahrenheitter(float *matriz, int linhas, int colunas) {
    float tempF[linhas][colunas]; 
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            tempF[x][y] = (matriz[x * linhas + y] * 1.8) + 32;
        }
        
    }
    printf("tabela em °C:\n");
    printer(matriz, linhas, colunas);
    printf("tabela em °F:\n");
    printer(tempF, linhas, colunas);
    return 0;
}
int main() {
    float tempC[4][5] = {0};
    anbt();
    printf("criador de matriz armazenando temperaturas em °C\ne criador de outra matiz com temperaturas em °F deluxe 44k 60fps\n");
    getter(tempC, 4, 5);
    fahrenheitter(tempC, 4, 5);
    system("pause");
    return 0;
}