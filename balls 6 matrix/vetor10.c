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
int halfer(int vetor[], int tamanho) {
    float half[tamanho];
    for (int i=0;i<tamanho;i++) {
        half[i] = (float)vetor[i] / 2;
    }
    printf("Whole table:\n");
    printer(vetor, tamanho);
    printf("Halfed table:\n");
    printerF(half, tamanho);
    return 0;
}
int printer(int vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int printerF(float vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° número: %.2f\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int whole[10] = {0};
    anbt();
    printf("pegador de tabela e criador de outra tabela\ncom os valores da metade da primeira tabela deluxe\n");
    getter(&whole, 10);
    halfer(whole, 10);
    system("pause");
    return 0;
}