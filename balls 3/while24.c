#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int c = 1;
    int numero = 0;
    int potenciador = 0;
    int resultado = 0;
    printf("digite um numero - ");
    scanf("%i", &numero);
    printf("digite o numero potenciador - ");
    scanf("%i", &potenciador);
    resultado = numero;
    while (c < potenciador) {
        resultado = resultado * numero;
        c++;
    }
    printf("resultado da potenciacao: %i", resultado);
    system("pause");
    return 0;
}