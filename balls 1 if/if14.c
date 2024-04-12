#include <stdio.h>
//balls 101
int main() {

    float sp; 
    float qt;

    printf("insira o codigo do produto\n");
    scanf("%f", &sp);

    printf("insira a quantidade do produto\n");
    scanf("%f", &qt);

    if (sp == 1) {
        sp = qt * 5.32;
    } 

    if (sp == 2) {
        sp = qt * 6.45;
    } 

    if (sp == 3) {
        sp = qt * 2.37;
    }
    
    if (sp == 4) {
        sp = qt * 5.32;
    }  

    if (sp == 5) {
        sp = qt * 6.45;
    }  

    printf("valor total:R$%f", sp);
    return 0;
}