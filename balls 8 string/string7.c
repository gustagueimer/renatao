#include <stdio.h>
#include <string.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int andrewAdder(char string1[], char string2[], int size) {
    char stringBuffer[size];
    char tok[] = {"T"};
    for (int i=0;i<size;i++) {
        stringBuffer[i] = string1[2+i];
    }
    strtok(string1, tok);
    strcat(string1, string2);
    strcat(string1, stringBuffer);
    printf("resultado: %s\n", string1);
    return 0;
}
int main() {
    char by[64] = {"By Tanenbaum"};
    char andrew[64] = {"Andrew"};
    anbt();
    printf("adicionador de \"Andrew\" na frase \"By Tanenbaum\" 64\n");
    andrewAdder(by, andrew, 64);
    system("pause");
    return 0;
}