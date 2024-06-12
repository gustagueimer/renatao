#include <stdio.h>
#include <string.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int iAndBeyondRemover(char string[], int size) {
    char stringBuffer[size];
    int toBeRemoved = 4; //quantidade de caracteres a serem removidos
    int startRemoval = 3; //numero da posição que vai começar a remover os caracteres
    int count = 0;
    int countRemoval = 0;
    for (int i=0;i<size;i++) {
        if ((i >= startRemoval) && (countRemoval <= toBeRemoved) ) {
            countRemoval++;
        } else {
            stringBuffer[count] = string[i];
            count++;
        }  
        //printf("countremove: %i\n", countRemoval);
        //printf("count: %i\n", count);
        //printf("%c\n", string[i]);
        //printf("%c\n", stringBuffer[count-1]);
    }
    printf("resultado: %s\n", stringBuffer);
    return 0;
}
int main() {
    char L[16] = {"machintosh"};
    anbt();
    printf("removedor de caracteres na palavra machintosh remaster\n");
    iAndBeyondRemover(L, 16);
    system("pause");
    return 0;
}