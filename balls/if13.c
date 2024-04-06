#include <stdio.h>
//balls 101
int main() {

    char select;
    float n1;
    float n2;

    printf("insira um numero\n");
    scanf("%f", &n1);

    printf("insira outro numero\n");
    scanf("%f", &n2);

    printf("selecione a operacao (+,-,*,/)");
    scanf("%s", &select);

    if (select == '+') {
        n1 = n1 + n2;
    } 

    if (select == '-') {
        n1= n1 - n2;
    } 

    if (select == '*') {
        n1 = n1 * n2;
    }
    
    if (select == '/') {
        n1 = n1 / n2;
    }  

    printf("operecao: %c; resultado: % f", select, n1);
    return 0;
}