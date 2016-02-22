#include <stdio.h>
#include <stdlib.h>

void troca(int a, int b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int main()
{
  int a, b;
  
  printf("Digite um valor de a");
  scanf("%i",&a);
  
  printf("Digite um valor de b");
  scanf("%i",&b);
  
  printf("O valor de a e b sao: %i %i", a, b);
  
  troca(a,b);
  
  printf("O valor de a e b sao: %i %i", a, b);

  system("PAUSE");	
  return 0;
}
