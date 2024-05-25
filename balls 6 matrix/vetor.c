#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(float * a) {
    for (int i = 0; i < 10; i++) {
        printf("insira um numero real - ");
        scanf("%f", &a[i]);
    }
    return 0;
}
int inversePrinter(float * a) {
    for (int i = 9; i >= 0; i--) {
        printf("%i° numero: %.2f\n", i+1, a[i]);
    }
    return 0;
}
int main() {
    float seggs[10] = {0};
    anbt();
    getter(&seggs);
    inversePrinter(&seggs);
    system("pause");
    return 0;
}