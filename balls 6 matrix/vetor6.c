#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[]) {
    for (int i=0;i<15;i++) {
        printf("informe um elemento da tabela numérica - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int fuser(int table1[], int table2[]) {
    int tableC[30] = {0};
    for (int i=0;i<15;i++) {
        tableC[i] = table1[i];
    }
    for (int i=15;i<30;i++) {
        tableC[i] = table2[i-15];
    }
    printf("value of the first table:\n");
    printer(table1, 15);
    printf("value of the second table:\n");
    printer(table2, 15);
    printf("fused table:\n");
    printer(tableC, 30);
    return 0;
}
int printer(int vetor[], int a) {
    for (int i=0;i<a;i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int tableA[15] = {0};
    int tableB[15] = {0};
    anbt();
    printf("juntador de duas tabelas em uma só deluxe\n");
    printf("insira os valores da primeirissima tabela:\n");
    getter(&tableA);
    printf("insira os valores da segundissima tabela:\n");
    getter(&tableB);
    fuser(tableA, tableB);
    system("pause");
    return 0;
}