#include <stdio.h>

float media(float notasFinais){
    
}

int main()
{
  int i = 0, qtdeAprovados = 0, max = 0;
  float notasFinais[100];
  
  printf("Digite a quantidade de alunos na turma:");
  scanf("%i",&max);
  
  for (i = 0; i < max; i++){
      printf("Digite a nota do aluno %i:", i+1);
      scanf("%f", &notasFinais[i]);
      
      if (notasFinais[i] >= 6)
      qtdeAprovados++;
  }
  
  for (i = 0; i < max; i++){
      printf("\nA nota do aluno %i eh: %g", i+1, notasFinais[i]);
      
  }
  
  int porcentagem = qtdeAprovados*100/max;
  
  printf("\nA quantidade de alunos aprovados eh %i e a porcentagem eh %i %% \n", qtdeAprovados, porcentagem );
  
  printf("\n\nMedia da classe: %g", media(notasFinais[]));
  
  system("PAUSE");	
  return 0;
}
