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
int finder(int vetor[], int *countPar, int *countImpar, int tamanho) {
    for (int i=0;i<tamanho;i++) {
        //debugging// printf("vetor %i: %i, ", i, vetor[i]);
        if (vetor[i] % 2 == 0) {
            //debugging// printf("é par\n");
            *countPar = *countPar + 1;
        } else {
            //debugging// printf("é impar\n");
            *countImpar = *countImpar + 1;
        }
    }
    //debugging// printf("\n\nqntPar: %i\n", *countPar);
    //debugging// printf("qntImpar: %i\n\n", *countImpar);
    return 0;
}
int organizer(int vetor1[], int vetor2[], int tamanho, int tamanhoPar, int tamanhoImpar) {
    int pares[tamanhoPar];
    int notPares[tamanhoImpar];
    for (int i=0;i<tamanhoPar;i++) {
        pares[i] = 0;
    }
    for (int i=0;i<tamanhoImpar;i++) {
        notPares[i] = 0;
    }
    for (int i=0;i<tamanho;i++) {
        int t;
        if (vetor1[i] % 2 == 0) {
            t = 0;
            while ((pares[t] != 0) && (t < tamanhoPar)) {t++;}
            pares[t] = vetor1[i];
            //debugging// printf("vt1 par happened\n");
            //debugging// printf("t: %i\n", t); printf("pares[%i]: %i\n\n", t, pares[t]);
        } else {
            t = 0;
            while ((notPares[t] != 0) && (t < tamanhoImpar)) {t++;}
            notPares[t] = vetor1[i];
            //debugging// printf("vt1 impar happened\n");
            //debugging// printf("notpares[%i]: %i\n\n", t, notPares[t]);
        }
    }
    for (int i=0;i<tamanho;i++) {
        int t;
        if (vetor2[i] % 2 == 0) {
            t = 0;
            while ((pares[t] != 0) && (t < tamanhoPar)) {t++;}
            pares[t] = vetor2[i];
           //debugging//  printf("vt2 par happened\n");
           //debugging//  printf("t: %i\n", t); printf("pares[%i]: %i\n\n", t, pares[t]);
        } else {
            t = 0;
            while ((notPares[t] != 0) && (t < tamanhoImpar)) {t++;}
            notPares[t] = vetor2[i];
            //debugging// printf("vt2 impar happened\n");
            //debugging// printf("notpares[%i]: %i\n\n", t, notPares[t]);
        }
    }
    printf("\nTabela de numeros pares:\n");
    printer(pares,tamanhoPar);
    printf("\nTabela de numeros impares:\n");
    printer(notPares, tamanhoImpar);
    return 0;
}
int main() {
    int starship[6] = {0};
    int superheavy[6] = {0};
    int qntPar = 0;
    int qntImpar = 0;
    anbt();
    printf("pegador de duas listas e separador de valores pares e impáres deluxe\n");
    printf("\ninsira os valores da primeira lista:\n");
    getter(&starship, 6);
    finder(starship, &qntPar, &qntImpar, 6);
    printf("\ninsira os valores da segunda lista:\n");
    getter(&superheavy, 6);
    finder(superheavy, &qntPar, &qntImpar, 6);
    organizer(starship, superheavy, 6, qntPar, qntImpar);
    system("pause");
    return 0;
}