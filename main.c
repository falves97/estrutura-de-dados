#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista_t* criar(void);
void destruir(lista_t *);
void inserir(lista_t *l);

int main(int argc, char const *argv[])
{
	lista_t *l = NULL;
	int op;

	do {
		printf("                   MENU                   \n");
  
		printf("1 - construir\n");
		printf("2 - destruir\n");
		printf("3 - está inicializada\n");
		printf("4 - tamanho\n");
		printf("5 - inserir\n");

		scanf("%d", &op);

		switch(op) {
			case 1: 
				l = criar();
			break;
			case 2:
				destruir(l);
			break;
			case 3:
				if(lista_inicializada(l)) {
					printf("lista inicializada\n");
				}
				else {
					printf("lista nao inicializada\n");
				}
			break;
			case 4:
				printf("Tamanho: %d\n", lista_tamanho(l));
			break;
			case 5:
				inserir(l);
			break;
		}
	}while(op != 0);
	
  return 0;
}

lista_t* criar(void) {
	lista_t* l;
	int capacidade;

	printf("Digite a capacidade: ");
	scanf("%d", &capacidade);

	l = lista_cria(capacidade);

	if(l != NULL){
		printf("lista criada\n");
	}

	return  l;
} 

void destruir(lista_t *l) {
	lista_destroi(l);
	if(l == NULL) {
		printf("lista destruída\n");
	}
}

void inserir(lista_t *l) {
	int r = lista_insere_cauda(l, 3);
	if(r == 1) {
		printf("inserido\n");
	}
	else {
		printf("nao inserido\n");
	}
}