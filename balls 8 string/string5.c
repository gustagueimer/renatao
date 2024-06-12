#include <stdio.h>
#include <string.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int verticalStringPrinterPlusPlus(char string[], int size) {
    int count = 0;
    for (int i=0;i<size;i++) {
        if (string[i] != '\0') {count++;}
    }
    for (int i=0;i<count;i++) {
        for (int j=0;j<=i;j++) {
            printf("%c", string[j]);
        }
        printf("\n");   
    }
    for (int i=count;i>=0;i--) {
        for (int j=0;j<i-1;j++) {
            printf("%c", string[j]);
        }
        printf("\n");   
    }
    return 0;
}
int main() {
    anbt();
    char balls[8] = {"LINUX"};
    printf("printador de LINUX em vertical pra frente e pra traz FHD\n");
    verticalStringPrinterPlusPlus(balls, 8);
    system("pause");
    return 0;
}