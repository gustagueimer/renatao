#include <stdio.h>
#include <windows.h>
#include <time.h>
#define ANBT UINT CPAGE_UTF8 = 65001; \
             SetConsoleOutputCP(CPAGE_UTF8);
#define pause system("pause");
#define escreva(A) (printf(A));
#define escreval(A, B) (printf(A, B));
#define leia(A, B) (scanf(A, B));
#define soma(A, B) ((A) + (B));
#define subtração(A, B) ((A) - (B));
#define multiplicação(A, B) ((A) * (B));
#define divisão(A, B) (((float)A) / ((float)B));
#define exponenciação(A) ((A) * (A));
//balls 101
int main() {
    ANBT;
    int A, B;
    time_t hora = time(NULL);
    escreval("hoje é %s ", asctime(localtime(&hora)))
    escreva("Faz o L \n");
    escreva("insira um valor - ");
    leia("%i", &A);
    escreva("insira outro valor - ");
    leia("%i", &B);
    int resultSm = soma(A, B);
    escreval("resultado soma = %i\n", resultSm);
    int resultSb = subtração(A, B);
    escreval("resultado subtração = %i\n", resultSb);
    int resultMp = multiplicação(A, B);
    escreval("resultado multiplicação = %i\n", resultMp);
    float resultDv = divisão(A, B);
    escreval("resultado divisão = %.2f\n", resultDv);
    int resultEp = exponenciação(A);
    escreval("resultado exponenciação = %i\n", resultEp);
    pause;
    return 0;
}