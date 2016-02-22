#include <stdio.h>
#include <stdlib.h>

int main()
{
  int * px;
  int x, y;
  
  x = 10;
  px = &x;
  
  printf("%d\n", x); //10
  printf("%p\n", px); //0028FF40
  printf("%p\n", &x); //0028FF40
  printf("%p\n", &px); //0028FF44
  
  *px = 15;
  
  printf("\n%d\n", x); //15
  printf("%p\n", px); //0028FF40
  printf("%d\n", *px); //15
  printf("%p\n", &x); //0028FF40
  printf("%p\n", &px); //0028FF44
  
  y = 3;
  px = &y;
  
  printf("\n%d\n", x); //15
  printf("%d\n", y); //3
  printf("%p\n", px); //0028FF3C
  printf("%d\n", *px); //3
  printf("%p\n", &x); //0028FF40
  printf("%p\n", &y); //0028FF3C
  printf("%p\n", &px); //0028FF44
  
  px++;
  
  printf("\n%p\n", px); //0028FF40
  printf("%d\n", *px); //15
  printf("%p\n", &px); //0028FF44
  
  px--;
  
  printf("\n%p\n", px); //0028FF3C
  printf("%d\n", *px); //3
  printf("%p\n", &px); //0028FF44
  
  system("PAUSE");	
  return 0;
}
