#include <stdio.h>
#include <windows.h>
#define LINES 2
#define ROWS 6
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("informe um elemento da tabela numérica - ");
            scanf("%i", &matrix[x][y]);
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
int printerMatrix(int matrix[LINES][ROWS], int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("Linha %i coluna %i: %i\n", x+1, y+1, matrix[x][y]);
        }
        printf("-------//-------\n");
    }
    return 0;
}
int compiladorVetor(int matriz[LINES][ROWS], int linhas, int colunas) {
    int vetor[colunas];
    for (int i=0;i<colunas;i++) {
        vetor[i] = 0;
    }
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("vetor %i: %i matriz[%i][%i]: %i\n", y, vetor[y], x, y, matriz[x][y]);
            vetor[y] = vetor[y] + matriz[x][y];
        }
    } 
    printf("vetor:\n");
    printerVetor(vetor, colunas);
    return 0;
}
int main() {
    int pqp[LINES][ROWS] = {0};
    anbt();
    printf("faltam 2h pra eu terminar isso, n tenho tempo pra explicar premium\n");
    printf("insira os valores da matriz:\n");
    getter(pqp, LINES, ROWS);
    printf("matriz original:\n");
    printerMatrix(pqp, LINES, ROWS);
    compiladorVetor(pqp, LINES, ROWS);
    system("pause");
    return 0;
}