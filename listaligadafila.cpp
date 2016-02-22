#include <stdlib.h>
#include <stdio.h>
struct no {
       int info;
       struct no * prox;
};

void imprimir (struct no * lt );
void inserir_final (int valor, struct no ** lt); 
int remover_inicio (struct no ** lt); 

int main () {
	struct no * lista = NULL;  //inicializacao da lista: lista vazia
   	int opcao, elem;

	do {
		printf ("\n 1-inserir na fila");
		printf ("\n 2-remover da fila");
		printf ("\n 3-imprimir fila  0-sair : ");
		scanf ("%d", &opcao);
		switch (opcao) {

			case 1 : printf ( "\n***Inserindo na fila***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 inserir_final (elem, &lista);
					 imprimir (lista);
					 break;		
			case 2 : printf ( "\n***Removendo da fila***");
			         if (lista != NULL) {
                         elem = remover_inicio (&lista);
					     printf ("\nValor removido: %d ", elem);
                     }
                     else
                         printf ("\Fila Vazia!");
					 imprimir (lista);
					 break;
			case 3 : imprimir (lista);
					 break;
			case 0 : printf ("\nSaindo....");
  	                 break;
			default: printf ("\nOpcao Invalida!");
		}
} while (opcao != 0);

system ("pause");
  	return (0);
}


void inserir_final (int valor, struct no ** lt) 
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

int remover_inicio (struct no ** lt) 
{
   	struct no * aux;
	int valor;
	aux = *lt;
	valor = aux->info;
	*lt = aux->prox;
	free (aux);
	return valor;
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


