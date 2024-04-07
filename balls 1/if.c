#include <stdio.h>
//balls 101
int main() {
   int idade;
   printf("verificador de aptidão a fazer cnh\n");
   printf("insira sua idade\n");
   scanf("%i", &idade);
   if (idade >= 18) {
    printf("estas apto");
   } else {
    printf("nao estas apto");
   }
   return 0;
}