#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("informe um elemento da tabela numérica - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int printer(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int pointlessSheet(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        if (i % 2 == 0) {
            vetor[i] = 2; 
        } else {
            vetor[i] = 1;
        }
    }
    printf("\ntabela após pointless:\n");
    printer(vetor, tamanho);
    return 0;
}
int main() {
    int timpani[15] = {0};
    anbt();
    printf("conversor de tabelas em algo pontless deluxe\n");
    printf("digite os numeros da tabela:\n");
    getter(&timpani, 15);
    pointlessSheet(&timpani, 15);
    system("pause");
    return 0;
}