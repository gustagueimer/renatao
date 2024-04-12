#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int c = 1;
    int cg[5];
    float valor[4];
    while (c < 6) {
        cg[c] = 0;
        valor[c] = 0;
        c++;
    }
    c = 1;
    printf("lojinha\n");
    printf("codigo|produtro|preco\n");
    printf("001|cachorro quente|R$2,50\n");
    printf("002|x salada       |R$3,00\n");
    printf("003|x tudo         |R$3,50\n");
    printf("004|refrigerante   |R$2,50\n");
    printf("digite 0 para finalizar a compra\n");
    while (c > 0) {
        printf("insira o codigo de um produto - ");
        scanf("%i", &cg[5]);
        switch (cg[5]) {
            case 0: c = 0; break;
            case 1: cg[1]++; break;
            case 2: cg[2]++; break;
            case 3: cg[3]++; break;
            case 4: cg[4]++; break;
            default: printf("opcao invalida\n");
        }
    }
    c = 1;
    printf("produtos selecionados: \n");
    while (c < 5) {
        switch (c) {
            case 1: if (cg[1] != 0) {printf("cachorros quentes:-%i   ", cg[1]); valor[1] = cg[1] * 2.50; printf("preco:R$%.2f\n", valor[1]);} break;
            case 2: if (cg[2] != 0) {printf("x saladas:---------%i   ", cg[2]); valor[2] = cg[2] * 3.00; printf("preco:R$%.2f\n", valor[2]);} break;
            case 3: if (cg[3] != 0) {printf("x tudos:-----------%i   ", cg[3]); valor[3] = cg[3] * 3.50; printf("preco:R$%.2f\n", valor[3]);} break;
            default: if (cg[4] != 0) {printf("refrigerantes:-----%i   ", cg[4]); valor[4] = cg[4] * 2.50; printf("preco:R$%.2f\n", valor[4]);} break;
        }
        c++;
    }
    valor[1] = valor[1] + valor[2] + valor[3] + valor[4];
    printf("valor total:                 R$%.2f\n", valor[1]);
    system("pause");
    return 0;
}