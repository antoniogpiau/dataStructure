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
		printf ("\n 1-inserir 2-remover");
		printf ("\n 3-imprimir  0-sair : ");
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1 : printf ( "\n***Inserindo ordenadamente na lista***");
					 printf ("\nValor a ser inserido: ");
					 scanf ("%d", &elem);
					 inserir_ordenado (elem, &lista);
					 break;	
			case 2 :
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


