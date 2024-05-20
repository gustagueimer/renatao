#include <stdio.h>
#include <windows.h>
//depende
void findLeap(year) {
    int bissex;
    bissex = year % 4;
    if (bissex == 0) {
        printf("o ano é bissexto\n");
    } else {
        printf("o ano não é bissexto\n");
    }
}

void findPrimo(year) {
    int primo;
    if(year == 2){
        primo = 1;
    }
    for(int i = year;i > 2;i--){
        if(year % (i-1) != 0 || year==3){
            primo=1;
        }else{
            primo=0;
            break;
        }
    }
    if(primo==1){
        printf("o ano é primo.\n");
    }else{
        printf("o ano não é primo.\n");
    }
}

void findJesus(year) {
    int a, b, c, d, e, f, g, h, i, j, k, l, month, day;
    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = (b+8) / 25;
    g = (b-f+1) / 3;
    h = (19*a+b-d-g+15) % 30;
    i = c / 4;
    j = c % 4;
    k = (32+2*e+2*i-h-j) % 7;
    l = (a+11*h+22*k) / 451;
    month = (h+k-7*l+114) / 31;
    day = 2+(h+k-7*l +144)%31;
    printf("a pascoa em %i será no dia %i/%i.\n", year, day, month);
}

int main() {
    unsigned int CPAGE_UTF8 = 65001; 
    SetConsoleOutputCP(CPAGE_UTF8);
    int year;
    printf("Insira um ano (depois de cristo) - ");
    scanf("%i", &year);
    findLeap(year);
    findPrimo(year);
    findJesus(year);
    system("pause");
    return 0;
}