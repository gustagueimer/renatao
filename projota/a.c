#include <stdio.h>
int troca(int a) {
    a = a + 1;
    printf("a: %i\n", a);
    return 0;
}
int main() {
    int a = 10;
    printf("aa: %i\n", a);
    troca(a);
    printf("ad: %i\n", a);
    return 0;
}