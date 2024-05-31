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
int valueInverter(int vetor[], int tamanho) {
    int invValor[tamanho];
    for (int i=0;i<tamanho;i++) {
        invValor[i] = vetor[i] * (-1);
    }
    printf("valores da tabela original:\n");
    printer(vetor, tamanho);
    printf("valores da tabela negativa:\n");
    printer(invValor, tamanho);
    return 0;
}
int printer(int vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int valor[10] = {0};
    anbt();
    printf("pegador de tabela e criador de outra tabela com\nos mesmos valores da primeira tabela porém negativo\n");
    getter(&valor, 10);
    valueInverter(valor, 10);
    system("pause");
    return 0;
}