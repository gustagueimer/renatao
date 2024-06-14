#include <stdio.h>
#include <windows.h>
#define array 10
//balls 101
int main() {
    int file[array] = {0};
    int c=0;
    FILE *fileInput;
    fileInput = fopen("file.txt", "r");
    while(fscanf(fileInput, "%d", &file[c]) != EOF) {
        c++;
    } 
    for (int i=0; i<array; i++) {
        printf("fileCopy[%d]: %d\n", i, file[i]);
    }
    fclose(fileInput);
    system("pause");
    return 0;
}