#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cliente {
       int numero;
       char nome[20];
       struct cliente * prox;
};

void imprimir (struct cliente * lt );
void inserir_final (int valor, char nome[20], struct cliente ** lt); 
int remover_inicio (struct cliente ** lt); 

int main () {
	struct cliente * lista = NULL;  //inicializacao da lista: lista vazia
   	int opcao, elem;
   	char n[20];

	do {
		printf ("\n 1-Novo cliente");
		printf ("\n 2-Caixa livre");
		printf ("\n 3-imprimir fila  0-sair : ");
		scanf ("%d", &opcao);
		switch (opcao) {

			case 1 : printf ( "\n***Novo Cliente***");
					 printf ("\nNome do cliente: ");
					 fflush(stdin);
					 gets(n);
					 printf ("\nNumero do conta: ");
					 scanf ("%d", &elem);
					 inserir_final (elem, n, &lista);
					 imprimir (lista);
					 break;		
			case 2 : printf ( "\n***Caixa livre***");
			         if (lista != NULL) {
                         elem = remover_inicio (&lista);
					     printf ("\nNome do cliente: %s", n);
                     }
                     else
                         printf ("\nFila Vazia!");
					 break;
			case 3 : if (lista != NULL) {
                        imprimir (lista);
                     }
                     else
                         printf ("\nFila Vazia!");
					 break;
			case 0 : printf ("\nSaindo....");
  	                 break;
			default: printf ("\n Opcao Invalida!");
		}
} while (opcao != 0);

system ("pause");
  	return (0);
}


void inserir_final (int valor, char nome[20], struct cliente ** lt) 
{
   	struct cliente * aux, * temp;
   	aux = (struct cliente *) malloc (sizeof(struct cliente));
	if (aux != NULL) {   
		aux->numero = valor;
		strcpy(aux->nome,nome);
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

int remover_inicio (struct cliente ** lt) 
{
   	struct cliente * aux;
	int valor;
	aux = *lt;
	valor = aux->numero;
	*lt = aux->prox;
	free (aux);
	return valor;
}
void imprimir (struct cliente * lt )
{    
 	printf ("\nFila:  ");
	while (lt != NULL) {         
		printf ("%s  ", lt->nome);
		lt = lt->prox;
 	}
	printf ("\n");
}
