#include "bib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

void insereFila(noAviao **pont, int id, int qtdTempo){
	assert(pont);
	srand((unsigned)(time(NULL)));
	qtdTempo = rand()%20;

	if(*pont == NULL){
		*pont = (noAviao *) malloc(sizeof(noAviao));
		if(*pont != NULL){
			(*pont)->id = id;
			(*pont)->qtdTempo = qtdTempo;
			(*pont)->prox = *pont;
		}
	}else{
		noAviao *aux = (noAviao *) malloc(sizeof(noAviao));
		aux->id = id;
		aux->qtdTempo = qtdTempo;
		aux->prox = (*pont)->prox;
		(*pont)->prox = aux;
	}
	printaFila(*pont);
}

void removeFila(noAviao **pont){
	assert(pont);

	if(*pont == NULL) return;
	
	noAviao *aux = *pont;
	while(aux->prox != (*pont)){
		aux->qtdTempo = aux->qtdTempo - 1;
		aux = aux->prox;
	}

	noAviao *pontPrim = (*pont)->prox;
	noAviao *pontPenult = (*pont)->prox;

	if(pontPrim->prox != pontPrim){
		while(pontPenult->prox != *pont){
			pontPenult = pontPenult->prox;
		}
		free(*pont);
		*pont = pontPenult;
		pontPenult->prox = pontPrim;
	}else{
		free(*pont);
		*pont = NULL;
	}
	printaFila(*pont);
}

void printaFila(noAviao *pont){
	if(pont == NULL){
		printf("Fila Vazia!\n");
	}else{
		noAviao *aux = pont;
		while(aux->prox != pont){
			aux = aux->prox;
			printf("ID: %d\tTempo restante: %d\n", aux->id, aux->qtdTempo);
		}

		printf("ID: %d\tTempo restante: %d\n", pont->id, pont->qtdTempo);
	}
}