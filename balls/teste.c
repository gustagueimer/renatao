#include <stdio.h>

int main() {
  int a, b;

  printf("insira um numero: ");
  scanf("%d", &a);

  printf("insira um segundo numero: ");
  scanf("%d", &b);

  if (a%b ==0){
    printf("sao multiplos");
    }else{
      printf("nao sao multiplos");
    }

return 0;
}