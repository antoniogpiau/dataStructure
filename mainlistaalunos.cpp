#include <stdlib.h>
#include <stdio.h>
struct no {
       int info;
       struct no * prox;
};

void imprimir (struct no * lt );

void inserir_ordenado(int valor, struct no ** lt){
     struct no * aux, * ant = NULL, * atual = *lt;
     int achou = 0;
     aux = (struct no *) malloc (sizeof(struct no));
     if (aux != NULL){
        aux -> info = valor;
        aux -> prox = NULL;
        while(atual != NULL && achou == 0){
              if (valor < atual -> info)
                 achou = 1;
              else{
                   ant = atual;
                   atual = atual-> prox;
              }
        }
        aux -> prox = atual;
        if(ant == NULL)
               *lt = aux;
        else
            ant -> prox = aux;     
     }else
     printf("\nMemoria insuficiente!");
}

void inserir_final(int elem, struct no ** lista){
    struct no * aux, * temp;
    
    aux = (struct no *)malloc(sizeof(struct no));
    
    aux->info = elem;
    aux->prox = NULL;
    
    if (aux != NULL){
       if ( *lista == NULL)
          *lista = aux;
       else{
            temp = *lista;
            while(temp->prox != NULL)
                 temp = temp->prox;
            temp->prox = aux;          
       }
    }else
         printf("\nMemoria insuficiente.");
}


int remover_final(struct no ** lista){
    struct no * temp = *lista;
    int valorRemovido;
    
   if (*lista != NULL){
      while (temp->prox->prox != NULL)
            temp = temp->prox;
      
      valorRemovido = temp->info;
      
      temp->prox = NULL;
      //free(temp);
      return valorRemovido; 
   }else
   printf("\nA lista ja esta vazia."); 
     
}

void inserir_inicio(int elem, struct no ** lista){
     struct no * aux;
     
     aux = (struct no *)malloc(sizeof(struct no));
     
     if (aux != NULL){
        aux->info = elem;
        aux->prox = *lista;
        *lista = aux;
     }else
         printf("\nMemoria insuficiente.");
}

int remover_inicio (struct no** lista){
    struct no * temp = *lista;
     int valorRemovido = 0;
     if (*lista != NULL){
        valorRemovido = temp->info;
        temp->info = temp->prox->info;
        temp->prox = temp->prox->prox;
        //free(temp->prox->prox);
         return valorRemovido;
     }else
     printf("\nA lista ja esta vazia.");
}

void imprimir (struct no * lt )
{    
 	printf ("\nLista:  ");
	while (lt != NULL) {         
		printf ( "%d ", lt->info );
		lt = lt->prox;
 	}
	printf ("\n");
}

int main () {
	struct no * lista = NULL;  //inicializacao da lista: lista vazia
   	int opcao, elem;

	do {
		printf ("\n 1-inserir inicio  2-inserir final  6-inserir ordenado");
		printf ("\n 3-remover inicio  4-remover final");
		printf ("\n 5-imprimir lista  0-sair : ");
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1 : printf ( "\n***Inserindo no inicio da lista***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 inserir_inicio (elem, &lista);
					 imprimir (lista);
					 break;
			case 2 : printf ( "\n***Inserindo no final da lista***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 inserir_final (elem, &lista);
					 imprimir (lista);
					 break;		
			case 3 : printf ( "\n***Removendo do inicio da lista***");
			         if (lista != NULL) {
                         elem = remover_inicio (&lista);
					     printf ("\nValor removido: %d ", elem);
                     }
                     else
                         printf ("\nLista Vazia!");
					 imprimir (lista);
					 break;
			case 4 : printf ( "\n***Removendo do final da lista***");
			         if (lista != NULL) {
                         elem = remover_final (&lista);
					     printf ("\nValor removido: %d ", elem);
                     }
                     else
                         printf ("\nLista Vazia!");
					 imprimir (lista);
					 break;
			case 5 : imprimir (lista);
					 break;
			case 6 : printf ( "\n***Inserindo ordenadamente na lista***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 inserir_ordenado (elem, &lista);
					 imprimir (lista);
					 break;		 
			case 0 : printf ("\nSaindo....");
  	                 break;
			default: printf ("\nOpcao Invalida!");
		}
} while (opcao != 0);

system ("pause");
  	return (0);
}


