#include <stdio.h>
#include <windows.h>
//balls 101
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
    printf("farmácio\n");
    printf("código| produto |preço\n");
    printf("---------------------------\n");
    printf("   001|remédio x|R$18,50\n");
    printf("   002|remédio y|R$6,35\n");
    printf("   003|remédio z|R$12,00\n");
    printf("   004|remédio 2|R$24,50\n");
    printf("digite 0 para finalizar a compra\n");
    while (c > 0) {
        printf("insira o código de um produto - ");
        scanf("%i", &cg[5]);
        switch (cg[5]) {
            case 0: c = 0; break;
            case 1: cg[1]++; break;
            case 2: cg[2]++; break;
            case 3: cg[3]++; break;
            case 4: cg[4]++; break;
            default: printf("código inválido\n");
        }
    }
    c = 1;
    printf("produtos selecionados: \n");
    while (c < 5) {
        switch (c) {
            case 1: if (cg[1] != 0) {printf("remédio x: %i          ", cg[1]); valor[1] = cg[1] * 18.50; printf("preço:R$%.2f\n", valor[1]);} break;
            case 2: if (cg[2] != 0) {printf("remédio y: %i          ", cg[2]); valor[2] = cg[2] * 6.35; printf("preço:R$%.2f\n", valor[2]);} break;
            case 3: if (cg[3] != 0) {printf("remédio z: %i          ", cg[3]); valor[3] = cg[3] * 12.00; printf("preço:R$%.2f\n", valor[3]);} break;
            default: if (cg[4] != 0) {printf("remédio 2: %i          ", cg[4]); valor[4] = cg[4] * 24.50; printf("preço:R$%.2f\n", valor[4]);}
        }
        c++;
    }
    valor[1] = valor[1] + valor[2] + valor[3] + valor[4];
    valor[2] = valor[1] / 10;
    valor[3] = valor[1] - valor[2];
    printf("valor total:                R$%.2f\n", valor[1]);
    printf("desconto:                   R$%.2f\n", valor[2]);
    printf("valor final:                R$%.2f\n", valor[3]);
    system("pause");
    return 0;
}