#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[20]) {
    for (int i=0;i<20;i++) {
        printf("insiraaaa um numerooo - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int math(int vetorA[20], int vetorB[20]) {
    int vectorC[20] = {0};
    for (int i=0;i<20;i++) {
        vectorC[i] = vetorA[i] - vetorB[i];
    }
    printer(vectorC);
    return 0;
}
int printer(int vetor[]) {
    for (int i=0 ; i<20 ; i++) {
        printf("%i° numero: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    int vectorA[20] = {0};
    int vectorB[20] = {0};
    anbt();
    printf("pegador de listas de numeros e realizador\nde sutração entre elas usando vetores deluxe\n");
    printf("insira os valores da lista A:\n");
    getter(&vectorA);
    printf("insira os valores da lista B:\n");
    getter(&vectorB);
    math(vectorA, vectorB);
    system("pause");
    return 0;
}