#include <stdio.h>
#include <windows.h>
#define array 10
//balls 101
int getter(int * a, int size) {
    for (int i = 0; i < size; i++) {
        printf("insira um numero real - ");
        scanf("%i", &a[i]);
    }
    return 0;
}
int main() {
    int file[array] = {0};
    getter(file, array);
    FILE *fileOutput;
    fileOutput = fopen("file.txt", "w");
    for (int i=0; i<array;i++) {
        fprintf(fileOutput, "%d\n", file[i]);
    }
    fclose(fileOutput);
    system("pause");
    return 0;
}