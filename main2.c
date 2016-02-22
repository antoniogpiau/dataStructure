#include <stdio.h>
  
int ehPrimo(int i){
   int total = 0, n;
   for (n=1; n <= i; n++){
       if (i%n==0)
       total++;
   }
   if (total <3)
      return 1;
      
   return 0;
}

int main()
{
  int i, j = 1, numPrimo[100];

  for (i = 1; i < 100; i++){
      if (ehPrimo(i)==1){
         numPrimo[j] = i;
         j++;
      }
  }
  
  for (i = 1; i < j; i++){
      printf("%i\n",numPrimo[i]);
  }

  system("PAUSE");	
  return 0;
}
