#include <stdio.h>
#include <string.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int verticalStringPrinterPlus(char string[], int size) {
    int count = 0;
    for (int i=0;i<size;i++) {
        if (string[i] != '\0') {count++;}
    }
    for (int i=0;i<count;i++) { 
        for (int j=0;j<=i;j++) {
            printf("%c", string[i]);
        }
        printf("\n");
    }
    return 0;
}
int main() {
    char abracadabra[16] = {"ABRACADABRA"};
    anbt();
    printf("impressor de abracadabra na vertical adicionando letras conforme a loccalização no vetor remake\n");
    verticalStringPrinterPlus(abracadabra, 16);
    system("pause");
    return 0;
}