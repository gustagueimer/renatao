#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    char clientela[30][150];
    float valorClientela[150];
    int clientelaDesconto[150];
    for (int i = 1; i < 151; i++) {
        printf("insira o nome do cliente - ");
        scanf("%s", &clientela[i]);
        printf("insira o valor total gasto pelo cliente no ano passado - R$");
        scanf("%f", &valorClientela[i]);
        if (valorClientela[i] < 500) {
            clientelaDesconto[i] = 10;
        } else {
            clientelaDesconto[i] = 15;
        }
    }
    for(int i = 1; i < 151; i++) {
        printf("cliente: %s   desconto: %i%;\n", clientela[i], clientelaDesconto[i]);
    }
    system("pause");
    return 0;
}