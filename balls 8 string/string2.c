#include <stdio.h>
#include <string.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int comparerConcatener(char string1[], char string2[], int size) {
    char space[] = {" "};
    int countBleck = 0;
    int countBlumiere = 0;
    for (int i=0;i<size;i++) {
        if (string1[i] != '\0') {
            countBleck++;
        }
        if (string2[i] != '\0') {
            countBlumiere++;
        }
    }
    if (countBleck == countBlumiere) {
        printf("as strings tem o mesmo tamanho\n");
        printf("string 1: %s\n", string1);
        printf("string 2: %s\n", string2);
    } else {
        strcat(string1, space);
        strcat(string1, string2);
        printf("as strings tem tamanho diferentes\n");
        printf("string concatenada: %s\n", string1);
    }
    return 0;
}
int main() {
    anbt();
    char string[64] = {"\0"};
    char string2[64] = {"\0"};
    printf("comparador de tamanho de string e concatetanor caso o tamanho das mesmas sejam diferentes deluxe\n");
    printf("insira a primeira string:\n");
    scanf("%s", string);
    printf("insira a segunda string:\n");
    scanf("%s", string2);
    comparerConcatener(string, string2, 64);
    system("pause");
    return 0;
}