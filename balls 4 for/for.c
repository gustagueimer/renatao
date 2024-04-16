#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int q;
    printf("insira um número - ");
    scanf("%i", &q);
    for (int i; i <= q; i++) {
    printf("%i\n", i);
    }
    system("pause");
    return 0;
}