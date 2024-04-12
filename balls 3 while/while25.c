#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int c = 1;
    int numero = 0;
    int multiplicador = 0;
    int resultado = 0;
    printf("digite um numero a ser multiplicado - ");
    scanf("%i", &numero);
    printf("digite o numero multiplicador - ");
    scanf("%i", &multiplicador);
    while (c <= multiplicador) {
        resultado = resultado + numero;
        c++;
    }
    printf("resultado da multiplicacao: %i", resultado);
    system("pause");
    return 0;
}