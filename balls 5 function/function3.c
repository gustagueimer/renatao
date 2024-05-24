#include <stdio.h>
#include <windows.h>
//balls 101
int seller(int a, int b[5], float c[4]) {
    printf("farmácio\n");
    printf("código| produto |preço\n");
    printf("---------------------------\n");
    printf("   001|remédio x|R$18,50\n");
    printf("   002|remédio y|R$6,35\n");
    printf("   003|remédio z|R$12,00\n");
    printf("   004|remédio 2|R$24,50\n");
    printf("digite 0 para finalizar a compra\n");
    while (a > 0) {
        printf("insira o código de um produto - ");
        scanf("%i", &b[5]);
        switch (b[5]) {
            case 0: a = 0; break;
            case 1: b[1]++; break;
            case 2: b[2]++; break;
            case 3: b[3]++; break;
            case 4: b[4]++; break;
            default: printf("código inválido\n");
        }
    }
    a = 1;
    printf("produtos selecionados: \n");
    while (a < 5) {
        switch (a) {
            case 1: if (b[1] != 0) {printf("remédio x: %i          ", b[1]); c[1] = b[1] * 18.50; printf("preço:R$%.2f\n", c[1]);} break;
            case 2: if (b[2] != 0) {printf("remédio y: %i          ", b[2]); c[2] = b[2] * 6.35; printf("preço:R$%.2f\n", c[2]);} break;
            case 3: if (b[3] != 0) {printf("remédio z: %i          ", b[3]); c[3] = b[3] * 12.00; printf("preço:R$%.2f\n", c[3]);} break;
            default: if (b[4] != 0) {printf("remédio 2: %i          ", b[4]); c[4] = b[4] * 24.50; printf("preço:R$%.2f\n", c[4]);}
        }
        a++;
    }
    c[1] = c[1] + c[2] + c[3] + c[4];
    c[2] = c[1] / 10;
    c[3] = c[1] - c[2];
    printf("valor total:                R$%.2f\n", c[1]);
    printf("desconto:                   R$%.2f\n", c[2]);
    printf("valor final:                R$%.2f\n", c[3]);
    system("pause");
    return 0;
}
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int c = 1;
    int cg[5];
    float valor[4];
    while (c < 6) {
        cg[c] = 0;
        valor[c] = 0;
        c++;
    }
    c = 1;
    seller(c, cg, valor);
    return 0;
}