#include <stdio.h>
#include <stdlib.h>

void troca( int *a, int *b )
{
   int aux;
   aux = *a;
   *a = *b;
   *b = aux;
}

int main()
{
//  int a,b;
//  
//  printf("A:");
//  scanf("%i", &a);
//  
//  printf("\nB:");
//  scanf("%i", &b);
//  
//  printf("Valores antes da troca A: %i   B:%i\n", a,b);
//  
//  troca(&a,&b);
//  
//  printf("Valores depois da troca A: %i   B:%i\n", a,b);
//  

    int a[5] = {10,15,20,25,30};
    int i = 0;
    
    for (; i<5; i++){
        printf("%d\n", a[i+1]); }   
    

  system("PAUSE");	
  return 0;
}
