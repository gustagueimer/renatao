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
int tabuador(int vetor[], int tamanho) {
    for (int i=1; i<=tamanho;i++) {
        vetor[i] = vetor[0] * (i+1);
    }
    printf("tabela da tabuada do %i:\n", vetor[0]);
    printerTabuada(vetor, 10);
    return 0;
}
int printerTabuada(int vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i x %i: %i\n", vetor[0], i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int tabulada = {0};
    anbt();
    printf("pegador de número e transformador em tabela de tabuada até 10 deluxe\n");
    getter(&tabulada, 1);
    tabuador(&tabulada, 10);
    system("pause");
    return 0;
}