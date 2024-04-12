#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    int tr [8];
    int tc [5];
    int vr;
    int vc;
    int c = 1;

    //input
    printf("insira o valor em reais (R$xx,xx): R$");
    scanf("%i, %i", &vr, &vc);
    printf("valor: R$:%i,%i\n", vr, vc);

    //processo
    while (c < 9) {
        switch (c) {
            case 1: tr[1] = vr / 200; vr = vr % 200; break;
            case 2: tr[2] = vr / 100; vr = vr % 100; break;
            case 3: tr[3] = vr / 50; vr = vr % 50; break;
            case 4: tr[4] = vr / 20; vr = vr % 20; break;
            case 5: tr[5] = vr / 10; vr = vr % 10; break;
            case 6: tr[6] = vr / 5; vr = vr % 5; break;
            case 7: tr[7] = vr / 2; break;
            default: tr[8] = vr % 2;
        }
        c = c + 1;
    }
    c = 1;
    
    while (c < 6) {
        switch (c) {
            case 1: tc[1] = vc / 50; vc = vc % 50; break;
            case 2: tc[2] = vc / 25; vc = vc % 25; break;
            case 3: tc[3] = vc / 10; vc = vc % 10; break;
            case 4: tc[4] = vc / 5; break;
            default: tc[5] = vc % 5;
        }
        c = c + 1;
    }
    c = 1;

    //seleção e exibição de resultados
    while (c < 9) {
        switch (c) {
            case 1: if (tr[c] > 0) { printf("notas de R$200: %i\n", tr[c]); } break;
            case 2: if (tr[c] > 0) { printf("notas de R$100: %i\n", tr[c]); } break;
            case 3: if (tr[c] > 0) { printf("notas de R$50: %i\n", tr[c]); } break;
            case 4: if (tr[c] > 0) { printf("notas de R$20: %i\n", tr[c]); } break;
            case 5: if (tr[c] > 0) { printf("notas de R$10: %i\n", tr[c]); } break;
            case 6: if (tr[c] > 0) { printf("notas de R$5: %i\n", tr[c]); } break;
            case 7: if (tr[c] > 0) { printf("notas de R$2: %i\n", tr[c]); } break;
            case 8: if (tr[c] > 0) { printf("moedas de R$1: %i\n", tr[c]); } break;
            default: ;
        }
        c = c + 1;
    }
    c = 1;
    while (c < 6) {
        switch (c) {
            case 1: if (tc[c] > 0) { printf("moedas de 50c: %i\n", tc[c]); } break;
            case 2: if (tc[c] > 0) { printf("moedas de 25c: %i\n", tc[c]); } break; 
            case 3: if (tc[c] > 0) { printf("moedas de 10c: %i\n", tc[c]); } break;
            case 4: if (tc[c] > 0) { printf("moedas de 5c: %i\n", tc[c]); } break;
            case 5: if (tc[c] > 0) { printf("moedas de 1c: %i\n", tc[c]); } break;
            default: ;
        }
        c = c + 1;
    }
    system("pause");
    return 0;
}