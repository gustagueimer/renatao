#include <math.h>
#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    float v = 1;
    for (int i = 0; i < 1;) {
        printf("insira um valor inteiro - ");
        scanf("%f", &v);
        if (v == -1) {
            i = 1;
        } else if (v < 0) {
        printf("valor: %.3f    valor²: %.3f    valor³: %.3f    sqrt: inexistente\n", v, v*v, v*(v*v), sqrt(v));
        } else {
        printf("valor: %.3f    valor²: %.3f    valor³: %.3f    sqrt: %.3f\n", v, v*v, v*(v*v), sqrt(v));
        }
    }
    system("pause");
    return 0;
}