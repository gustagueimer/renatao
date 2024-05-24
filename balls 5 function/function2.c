#include <stdio.h>
#include <windows.h>
//balls 101
int getDate(int c, int data[3]) {
    while (c != 1) {
        printf("insira uma data (xx/xx/xxxx) - ");
        scanf("%i/ %i/ %i", &data[1], &data[2], &data[3]);
        for (int i = 1; i < 4; i++) {
            switch (i) {
                case 1: if (data[1] > 31) {printf("data inválida\n"); i = 4;} break;
                case 2: if (data[2] > 12) {printf("data inválida\n"); i = 4;} break;
                default: if (data[3] < 0) {printf("data inválida\n"); i = 4;} else {printf("data: %i/%i/%i\n", data[1], data[2], data[3]); c = 1;}
            }
        }
    }
    switch (data[2]) {
        case 1: data[1] = data[1]; break;
        case 2: data[1] = data[1] + 31; break;
        case 3: data[1] = data[1] + 59; break;
        case 4: data[1] = data[1] + 90; break;
        case 5: data[1] = data[1] + 120; break;
        case 6: data[1] = data[1] + 151; break;
        case 7: data[1] = data[1] + 181; break;
        case 8: data[1] = data[1] + 212; break;
        case 9: data[1] = data[1] + 243; break;
        case 10: data[1] = data[1] + 273; break;
        case 11: data[1] = data[1] + 304; break;
        case 12: data[1] = data[1] + 334; break;
    }
    printf("%i° dia do ano\n", data[1]);
    return 0;
}
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int c;
    int data[3];
    getDate(c, data);
    system("pause");
    return 0;
}