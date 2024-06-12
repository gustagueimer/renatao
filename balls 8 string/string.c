#include <stdio.h>
#include <windows.h>
#include <string.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int comparer(char nome1[], char nome2[], int size) {
    int count1 = 0;
    int count2 = 0;
    for (int i=0;i<size;i++) {
        if (nome1[i] != 0) {
            count1++;
        }
        if (nome2[i] != 0) {
            count2++;
        }
    }
    if (count1 > count2) {
        printf("palavra 1 é maior que palavra 2\n");
        for (int i=0;i<size;i++){
           nome1[i] = toupper(nome1[i]);
        }
        for (int i=0;i<size;i++) {
            nome2[i] = tolower(nome2[i]);
        }
        printf("nome 1: %s\n", nome1);
        printf("nome 2: %s\n", nome2);
    } else if (count2 > count1){
        printf("palavra 2 é maior que palavra 1\n");
        for (int i=0;i<size;i++){
           nome2[i] = toupper(nome2[i]);
        }
        for (int i=0;i<size;i++) {
            nome1[i] = tolower(nome1[i]);
        }
        printf("nome 1: %s\n", nome1);
        printf("nome 2: %s\n", nome2);
    } else {
        printf("ambas palavras tem o mesmo tamanho\n");
        printf("nome 1: %s\n", nome1);
        printf("nome 2: %s\n", nome2);
    }
    return 0;
}
int main() {
    anbt();
    char nome1[64] = {0};
    char nome2[64] = {0};
    printf("comparador de string e botador da maior em caixa alta deluxe HD\n");
    printf("digite a primeira palavra:\n");
    scanf("%s", nome1);
    printf("digite a segunda palavra:\n");
    scanf("%s", nome2);
    comparer(nome1, nome2, 64);
    system("pause");
    return 0;
}