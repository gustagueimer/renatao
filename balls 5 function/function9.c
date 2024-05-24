#include <stdio.h>
#include <windows.h>
int clientelaFunction(char c[30][150], float vc[150], int cd[150]) {
    for (int i = 1; i < 151; i++) {
        printf("insira o nome do cliente - ");
        scanf("%s", &c[i]);
        printf("insira o valor total gasto pelo cliente no ano passado - R$");
        scanf("%f", &vc[i]);
        if (vc[i] < 500) {
            cd[i] = 10;
        } else {
            cd[i] = 15;
        }
    }
    for(int i = 1; i < 151; i++) {
        printf("cliente: %s   desconto: %i%;\n", c[i], cd[i]);
    }
    return 0;
}
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    char clientela[30][150];
    float valorClientela[150];
    int clientelaDesconto[150];
    clientelaFunction(clientela, valorClientela, clientelaDesconto);
    system("pause");
    return 0;
}