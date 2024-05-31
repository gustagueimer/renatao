#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(float vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("informe um elemento da tabela numérica - ");
        scanf("%f", &vetor[i]);
    }
    return 0;
}
int fahrenheitter(float vetor[], int tamanho) {
    float tempF[tamanho];
    for (int i=0;i<tamanho;i++) {
        tempF[i] = (vetor[i] * 1.8) + 32;
    }
    printf("tabela em °C:\n");
    printerF(vetor, 10);
    printf("tabela em °F:\n");
    printerF(tempF, 10);
    return 0;
}
int printerF(float vetor[], int tamanho) {
    for (int i=0 ; i<tamanho ; i++) {
        printf("%i° número: %.2f\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    float tempC[10] = {0};
    anbt();
    printf("pegador de tabela de temperaturas em\n°C pra tabela de temperaturas em °F deluxe\n");
    getter(tempC, 10);
    fahrenheitter(tempC, 10);
    system("pause");
    return 0;
}