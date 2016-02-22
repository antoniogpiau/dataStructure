#include <stdlib.h>
#include <stdio.h>
struct no {
       int info;
       struct no * prox;
};
void inserir_final (int valor, struct no ** lt); 
void inserir_inicio (int valor, struct no ** lt); 
int remover_final (struct no ** lt); 
int remover_inicio (struct no ** lt); 
void imprimir (struct no * lt );

int main () {
	struct no * lista = NULL;  //inicializacao da lista: lista vazia
   	int opcao, elem;

	do {
		printf ("\n 1-inserir inicio  2-inserir final");
		printf ("\n 3-remover inicio  4-remover final");
		printf ("\n 5-imprimir lista  0-sair : ");
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1:	printf ( "\n***Inserindo no inicio da lista***");
					printf ("\nValor a ser inserido: ");
					scanf ("%d", &elem);
					inserir_inicio (elem, &lista);
					imprimir (lista);
					break;
			case 2:	printf ( "\n***Inserindo no final da lista***");
					printf ("\nValor a ser inserido: ");
					scanf ("%d", &elem);
					inserir_final (elem, &lista);
					imprimir (lista);
					break;		
			case 3:	printf ( "\n***Removendo do inicio da lista***");
			      	if (lista != NULL) {
                   		elem = remover_inicio (&lista);
					  	printf ("\nValor removido: %d ", elem);
                 	}
                 	else
						printf ("\nLista Vazia!");
					imprimir (lista);
					break;
			case 4:	printf ( "\n***Removendo do final da lista***");
			      	if (lista != NULL) {
                  		elem = remover_final (&lista);
					   	printf ("\nValor removido: %d ", elem);
                 	}
                 	else
						printf ("\nLista Vazia!");
					imprimir (lista);
					break;
			case 5:	imprimir (lista);
					break;
			case 0:	printf ("\nSaindo....");
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
void inserir_inicio (int valor, struct no ** lt) 
{
   	struct no * aux;
   	aux = (struct no *) malloc (sizeof(struct no));
	if (aux != NULL) {   
		aux->info = valor;
		aux->prox = *lt;
		*lt = aux;
	}
	else
		printf("\nMemoria insuficiente!");    
}
int remover_final (struct no ** lt) 
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



