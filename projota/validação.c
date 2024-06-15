#include <stdio.h>
#include <string.h>
#include <windows.h>
#define VALIDO 0
#define INVALIDO 1
// função que valida um input
int validInput(char *input, int size) {
    for (int i=0;i<size;i++) {
        // debugging // printf("input[%d]: %c\n", i, input[i]);
        if(!isdigit(input[i]) && (input[i] != '\0')) {
            return INVALIDO;
        }
       // debugging // printf("ainda no for\n");
    }
    // debugging // printf("saiu do for\n");
    return VALIDO;
}
void varTempClean(char *varTemp) {
    memcpy(varTemp, "\0", 8);
    //for (int i=0; i<8; i++) {
        // strcpy(varTemp, "\0");

    //}
}
int main() {
    char varTemp[8] = {'\0'};
    int a = 0;
    do {
    printf("insira um valor - ");
    scanf("%s", &varTemp);
    } while (validInput(varTemp, 8) == INVALIDO);
    a = atoi(varTemp);
    varTempClean(varTemp);
    printf("a: %d\n", a);
    printf("vartemp: %s", varTemp);
    return 0;
}