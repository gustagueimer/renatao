#include <stdio.h>
#include <string.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int verticalStringPrinter(char string[], int size) {
    int count = 0;
    for (int i=0;i<size;i++) {
        if (string[i] != '\0') {count++;}
    }
    for (int i=0;i<count;i++) {
        printf("%c\n", string[i]);
    }
    return 0;
}
int main() {
    anbt();
    char streeng[64] = {"\0"};
    char string[8] = {"CASA"};
    printf("impressor de string na vertical ultra deluxe\n");
    printf("insira a string:\n");
    scanf("%s", streeng);
    verticalStringPrinter(streeng, 64);
    printf("string \"casa\" na vertical:\n");
    verticalStringPrinter(string, 8);
    return 0;
}