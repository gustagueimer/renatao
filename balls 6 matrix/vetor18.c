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
int menorNum(int vetor[], int tamanho, int maiorNum) {
    int menor=maiorNum;
    for (int i=0;i<tamanho;i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    printf("Menor numero da tabela: %i\n", menor);

}
int maiorNum(int vetor[], int tamanho) {
    int maior=0;
    for (int i=0;i<tamanho;i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    printf("\nMaior numero da tabela: %i\n", maior);
    menorNum(vetor, tamanho, maior);
}
int mediaTabela(int vetor[], int tamanho) {
    float media=0;
    for (int i=0;i<tamanho;i++) {
        media = media + (float)vetor[i];
    }
    media = media / tamanho;
    printf("Média da tabela: %.2f\n\n", media);
}
int main() {
    int olly[12];
    anbt();
    printf("pegador de tabela e descobridor de maior numero, menor numero e média deluxe\n");
    printf("defina os valores da tabela:\n");
    getter(&olly, 12);
    maiorNum(olly, 12);
    mediaTabela(olly, 12);
    system("pause");
    return 0;
}