#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int n = 1;
    int nc[4];
    while (n < 5) {
        nc[n] = 0;
        n++;
    }
    for (int i; i < 15; i++) {
        printf("insira um número - ");
        scanf("%i", &n);
        switch (n) {
            case 0 ... 25: nc[1]++; break;
            case 26 ... 50: nc[2]++; break;
            case 51 ... 75: nc[3]++; break;
            case 76 ... 100: nc[4]++; break;
        }
    }
    printf("números no intervalo de 0 a 25: %i\n", nc[1]);
    printf("números no intervalo de 26 a 50: %i\n", nc[2]);
    printf("números no intervalo de 51 a 75: %i\n", nc[3]);
    printf("números no intervalo de 76 a 100: %i\n", nc[4]);
    system("pause");
    return 0;
} 