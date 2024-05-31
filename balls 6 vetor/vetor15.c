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
int fuser(int table1[], int table2[], int tamanho) {
    int island[tamanho * 2];
    for (int i=0;i<tamanho;i++) {
        island[i] = table1[i];
    }
    for (int i=tamanho;i<(tamanho*2);i++) {
        island[i] = table2[i-tamanho];
    }
    printf("\nvalues of the first table:\n");
    printer(table1, tamanho);
    printf("\nvalues of the second table:\n");
    printer(table2, tamanho);
    printf("\nfused table:\n");
    printer(island, tamanho*2);
    return 0;
}
int main() {
    int dragon[10] = {0};
    int roost[10] = {0};
    anbt();
    printf("fundidor de tabelas deluxe 2\n");
    printf("insira os dados da primeira tabela:\n");
    getter(&dragon, 10);
    printf("\ninsira os dados da segunda tabela:\n");
    getter(&roost, 10);
    fuser(dragon, roost, 10);
    system("pause");
    return 0;
}