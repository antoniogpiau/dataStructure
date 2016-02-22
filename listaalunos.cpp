#include <stdlib.h>
#include <stdio.h>
struct no {
       int info;
       struct no * prox;
};

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
			case 1 : printf ( "\n***Inserindo no inicio da lista***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 //inserir_inicio (elem, &lista);
					 imprimir (lista);
					 break;
			case 2 : printf ( "\n***Inserindo no final da lista***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 //inserir_final (elem, &lista);
					 imprimir (lista);
					 break;		
			case 3 : printf ( "\n***Removendo do inicio da lista***");
			         if (lista != NULL) {
                         //elem = remover_inicio (&lista);
					     printf ("\nValor removido: %d ", elem);
                     }
                     else
                         printf ("\nLista Vazia!");
					 imprimir (lista);
					 break;
			case 4 : printf ( "\n***Removendo do final da lista***");
			         if (lista != NULL) {
                         //elem = remover_final (&lista);
					     printf ("\nValor removido: %d ", elem);
                     }
                     else
                         printf ("\nLista Vazia!");
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

void imprimir (struct no * lt )
{    
 	printf ("\nLista:  ");
	while (lt != NULL) {         
		printf ( "%d ", lt->info );
		lt = lt->prox;
 	}
	printf ("\n");
}





