#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("escolha um número de 1 a 60 - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int printer(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("número %i\n", vetor[i]);
    }
    return 0;
}
int defMegasena(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i=0;i<tamanho;i++) {
        vetor[i] = rand() % 60;
    }
    printf("\nNumeros da megasena:\n");
    printer(vetor, tamanho);
    return 0;
}
int compMegasena(int vetorJogo[], int vetorMegasena[], int tamanho) {
    int qntIguais=0;
    for (int i=0;i<tamanho;i++) {
        for (int c=0;c<tamanho;c++) {
            //debugging// printf("nj[%i]: %i  nm[%i]: %i\n", i, vetorJogo[i], c, vetorMegasena[c]);
            if (vetorJogo[i] == vetorMegasena[c]) {
                qntIguais++;
                //debugging// printf("somou\n");
                break;
            }
        }
    }
    //debugging// printf("qntIguais: %i\n", qntIguais);
    if (qntIguais != 0) {
        int resultados[qntIguais];
        for (int i=0;i<qntIguais;i++) {
            resultados[i] = 0;
        }
        int c=0;
        for (int i=0;i<tamanho;i++) {
            for (int f=0;f<tamanho;f++) {
                //debugging// printf("nj[%i]: %i  nm[%i]: %i\n", i, vetorJogo[i], f, vetorMegasena[f]);
                if (vetorJogo[i] == vetorMegasena[f]) {
                    resultados[c] = vetorJogo[i];
                    //debugging// printf("r[%i]:%i\n\n", c, resultados[c]);
                    c++;
                    break;
                }
            }
        }
        printf("\nNúmeros jogados:\n");
        printer(vetorJogo, tamanho);
        printf("\nNúmeros acertados:\n");
        printer(resultados, qntIguais);
    } else {
        printf("\nNenhum número foi acertado :( \n");
    }
    return 0;
}
int main() {
    int rauru[6] = {0};
    int mineru[6] = {0};
    anbt();
    printf("pegador de numeros da megasena e sorteador do\nresultado com comparação aos numeros escolhidos deluxe 2024 atualizado\n");
    getter(&rauru, 6);
    printer(rauru, 6);
    defMegasena(&mineru, 6);
    compMegasena(rauru, mineru, 6);
    system("pause");
    return 0;
}