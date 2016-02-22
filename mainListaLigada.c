#include <stdio.h>
#include <stdlib.h>


struct no{
    int info;
    struct no * prox;       
};

typedef struct no No;

void imprime(No *no){
     No *aux = no;
     while (aux != NULL){
         printf("Info do No: %i\n", aux->info);
         aux = aux->prox;
     }
}

//void inserirNoFinal(No *aux, No *lista){
     


//}

int main()
{   
    
    No *aux, *temp, *lista = NULL;
    
    int n = 5, i = 0;
    
    
    for (i = 0; i < n; i++){
        if (!aux){
           printf("Erro de memoria.");
        }else{
              
              aux = (No *) malloc (sizeof(No));
              aux->info = i;
              aux->prox = NULL;
              
              if (lista ==NULL){
                 lista = aux;
              }else
              {
               temp = lista;
               
               while (temp -> prox !=NULL)
                     temp = temp-> prox;
                     
                     temp -> prox = aux;
              }  
        }
    }
    
   imprime(lista);
   
   free(aux);
  
  system("PAUSE");	
  return 0;
}
