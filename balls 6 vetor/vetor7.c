#include<stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[]) {
    for (int i=0;i<20;i++) {
        printf("coloque um número - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int inverter(int vetor[]) {
    int count[20] = {0};
    int inv = 19;
    for (int i=0;i<20;i++) {
        count[i] = vetor[inv];
        inv--;  
    }
    printf("tabela original:\n");
    printer(vetor);
    printf("tabela invertida:\n");
    printer(count);
    return 0;
}
int printer(int vetor[]) {
    for (int i=0;i<20;i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int bleck[20] = {0};
    anbt();
    printf("pegador de tabela e criador de tabela inversa deluxe\n");
    getter(&bleck);
    inverter(bleck);
    system("pause");
    return 0;
}