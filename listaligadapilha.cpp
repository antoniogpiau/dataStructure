#include <stdlib.h>
#include <stdio.h>
struct no {
       int info;
       struct no * prox;
};

void imprimir (struct no * lt );

void empilhar (int valor, struct no ** lt) 
{
   	struct no * aux, * temp;
   	aux = (struct no *) malloc (sizeof(struct no));
	if (aux != NULL) {   
		aux->info = valor;
		aux->prox = NULL;
		if ( *lt == NULL ) 	// lista vazia
		   	*lt = aux;
       	else {
          	temp = * lt;
          	while (temp->prox != NULL)
          		temp = temp->prox;
          	temp->prox = aux;
      	}
	}
	else
		printf("\nMemoria insuficiente!");    
}

int desempilhar (struct no ** lt) 
{
   	struct no * aux, * temp;
	int valor;
	aux = NULL;
   	temp = *lt;
	while (temp->prox != NULL)
	{
		aux = temp;
		temp = temp->prox;
	}
	valor = temp->info;
	if (aux == NULL)
		*lt = NULL;
	else
		aux->prox = NULL;
	free (temp);
	return valor;
}

void imprimir (struct no * lt )
{    
 	printf ("\nPilha:  ");
	while (lt != NULL) {         
		printf ( "%d ", lt->info );
		lt = lt->prox;
 	}
	printf ("\n");
}

int main () {
	struct no * lista = NULL;  //inicializacao da lista: lista vazia
   	int opcao, elem, primeiro;

	do {
		printf ("\n 1-Empilhar");
		printf ("\n 2-Desempilhar");
		printf ("\n 3-Topo");
		printf ("\n 4-Primeiro");
		printf ("\n 5-imprimir pilha  0-sair : ");
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1 : printf ( "\n***Empilhando***");
					 printf ("\nValor a ser empilhado: ");
					 scanf ("%d", &elem);
					 
					 if (lista == NULL)
					 primeiro = elem;
					 
					 empilhar (elem, &lista);
					 imprimir (lista);
					 break;		
			case 2 : printf ( "\n***Desempilhando***");
			         if (lista != NULL) {
                         elem = desempilhar (&lista);
					     printf ("\nValor a ser desempilhado: %d ", elem);
                     }
                     else
                         printf ("\nPilha Vazia!");
					 imprimir (lista);
					 break;
		    case 3 : printf ( "\n***Topo***");
			         if (lista != NULL) {
                         elem = desempilhar(&lista);
                         empilhar(elem, &lista);
					     printf ("\nTopo: %d ", elem);
                     }
                     else
                         printf ("\nPilha Vazia!");
					 imprimir (lista);
					 break;
           case 4 : printf ( "\n***Primeiro elemento***");
			         if (lista != NULL) 
					     printf ("\nPrimeiro: %d ", primeiro);
                     else
                         printf ("\nPilha Vazia!");
					 imprimir (lista);
					 break;
			case 5 : imprimir (lista);
					 break;	 
			case 0 : printf ("\nSaindo....");
  	                 break;
			default: printf ("\nOpcao Invalida!");
		}
} while (opcao != 0);

system ("pause");
  	return (0);
}

