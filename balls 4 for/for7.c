#include <stdio.h>
#include <windows.h>
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    printf("impressor de números entre 1000 a 199 que divididos por 11 sobram 5\n");
    for (int i = 1000; i < 2000; i++){
        if (i % 11 == 5) {
            printf("%i\n", i);
        } 
    }
    system("pause");
    return 0;
}