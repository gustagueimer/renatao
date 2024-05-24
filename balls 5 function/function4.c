#include <stdio.h>
#include <windows.h>
//balls 101
int getSmallestNumber(int n[2]) {
    printf("digite 0 para parar\n");
    printf("insira um número - ");
    scanf("%i", &n[1]);
    for (int i; i < 2; i++) {
        n[2] = 0;
        printf("insira um número - ");
        scanf("%i", &n[2]);
        switch (n[2]) {
            case 0: printf("menor número digitado: %i\n", n[1]); i = 2; break;
            default: if (n[2] < n[1]) { n[1] = n[2]; } i = 0; 
        } 
    }
    return 0;
}
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int n[2];
    getSmallestNumber(n);
    system("pause");
    return 0;
}