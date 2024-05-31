#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[8]){
    for (int i=0 ; i<8 ; i++) {
        printf("digite um numero - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int byThree(int vetor[8]) {
    int vetor3x[8]= {0};
    for (int i=0 ; i<8 ; i++) {
        vetor3x[i] = vetor[i] * 3;
    }
    printer(vetor3x);
    return 0;
}
int printer(int vetor[8]) {
    for (int i=0 ; i<8 ; i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int vectoor[8] = {0};
    anbt();
    printf("pegador de numeros inteiros e multiplicador\npor 3 usando vetores deluxe (2020 atualizado)\n");
    getter(vectoor);
    byThree(vectoor);
    system("pause");
    return 0;
}