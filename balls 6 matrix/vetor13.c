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
int idkman(int vetor[], int tamanho) {
    int shiny[tamanho];
    for (int i=0;i<tamanho;i++) {
        if (vetor[i] % 2 != 0) {
            shiny[i] = vetor[i] * 2;
        } else {
            shiny[i] = vetor[i];
        }
    }
    printf("Tabela original:\n");
    printer(vetor, 12);
    printf("Tabela nova:\n");
    printer(shiny, 12);
    return 0;
}
int printer(int vetor[], int tamanho) {
    for (int i=0;i<tamanho ;i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int japa[12] = {0};
    anbt();
    printf("muito trampo pra explicar deluxe\n");
    getter(&japa, 12);
    idkman(japa, 12);
    system("pause");
    return 0;
}