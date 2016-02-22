#include <stdio.h>
#include <stdlib.h>


void imprimeNum(int n){
     int i = 0;
     
     for (; i < n; i++)
     printf("%i - ", i+1);
         
     printf("fim \n");
}

int printNum(int n){ 
    
    if (n == 0)
    return 0;
    
    printf("%i - ", n + printNum(n-1));
    
    return (n - (n-1));
}

int main()
{
    int num = 0;
    
    while (num <= 0){
          printf("Digite um numero natural valido: ");
          scanf("%i", &num);
    }
    
    //printf("Endereco do numero : %p \n", &num);
    printNum(num);
  
  system("PAUSE");	
  return 0;
}
