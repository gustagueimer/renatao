#include <stdio.h>
#include <windows.h>
//balls 101
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int t = 0;
    float ac = 1.50;
    for (float az = 1.10; az <= ac; az = az + 0.03) {
        ac = ac + 0.02;
        t++;
    }
    printf("%i anos até zé ser maior que chico\n", t);
    system("pause");
    return 0;
}