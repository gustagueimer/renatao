#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[]) {
    for (int i=0;i<4;i++) {
        printf("informe um elemento da tabela numérica - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int maincraft(int vetor[]) {
    int vectorMinceraft[15] = {0};
    for (int i=0;i<4;i++) {
        vectorMinceraft[i] = vetor[i] * vetor[i];
    }
    printf("tabela original:\n");
    printer(vetor);
    printf("(nova) tabela ao quadrado:\n");
    printer(vectorMinceraft);
    return 0;
}
int printer(int vetor[]) {
    for (int i=0 ;i<4;i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int vector[15] = {0};
    anbt();
    printf("pegador de tabela e criador de outra tabela com\nvalores ao quadrado relativos a outra tabela deluxe\n");
    printf("defina a primeira tabela:\n");
    getter(&vector);
    maincraft(vector);
    system("pause");
    return 0;
}