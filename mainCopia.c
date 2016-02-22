#include <stdio.h>

struct aluno{
       int ra;
       float nota;
       };

typedef struct aluno Aluno;

float CalculaMedia(int n, Aluno p[]){
    int i;
    float soma = 0;
    
    for (i = 0;i < n;i++)
        soma += p[i]->nota[i];
    
    return soma/n;
}

int main()
{
  int n, i;
  //float *p;
  Aluno *p;
  
  printf("Quantos alunos existem na turma: ");
  scanf("%d", &n);
  printf("\n");
  
  p = (Aluno *) malloc (n * sizeof(Aluno));
  
  if (!p)
  {
     printf("Nao existe memoria suficiente!\n");
  }
  else{
       
     for (i = 0; i < n; i++)
     {
        printf("\nRa do aluno %d: ", i+1);
        scanf("%f", p[i]->ra);
        printf("\nNota do aluno %d: ", i+1);
        scanf("%f", p[i]->nota);
     }
     
     printf("\nMedia da Turma: %g\n", CalculaMedia(n,p));
     
  }
  
  free (p);
  
  system("PAUSE");	
  return 0;
}
