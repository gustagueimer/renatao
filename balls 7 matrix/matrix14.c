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
int printerVetor(int vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int printerMatrix(int *matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("Linha %i coluna %i: %i\n", x+1, y+1, matrix[x * linhas + y]);
        }
        printf("-------//-------\n");
    }
    return 0;
}
int sheet(int *matriz, int linhas, int colunas) {
    int vetor[linhas];
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            if (x == y) {
                vetor[x] = matriz[x * linhas + y] * 5;
            }
        }
    }
    printf("valor da matriz original:\n");
    printerMatrix(matriz, linhas, colunas);
    printf("valores do vetor:\n");
    printerVetor(vetor, linhas);
    return 0;

}
int main() {
    int mtv[4][4] = {0};
    anbt();
    printf("criador de matriz e criador de vetor com valores dos elementos da diagonal do vetor multiplicados por 5 delixe\n");
    printf("insira os valores da matriz:\n");
    getter(mtv, 4, 4);
    sheet(mtv, 4, 4);
    system("pause");
    return 0;
}