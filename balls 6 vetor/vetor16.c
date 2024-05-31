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
int negativeCounter(int vetor[], int tamanho) {
    int qntNegativos = 0;
    for (int i=0;i<tamanho;i++) {
        if (vetor[i] < 0) {
            qntNegativos++;
        }
    }
    printf("\nquantidde de numeros negativos na tabela: %i\n\n", qntNegativos);
    return 0;
}
int main() {
    int blumiere[6] = {0};
    anbt();
    printf("pegador de tabela e contador de quantos numeros negativos tal tabela tem deluxe\n");
    printf("insira os valores da tabela:\n");
    getter(&blumiere, 6);
    negativeCounter(blumiere, 6);
    system("pause");
    return 0;
}