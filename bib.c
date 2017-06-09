#include "bib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void insereFila(noAviao **pont, int id, int qtdCombustivel, int *nAvioes, int nPrateleira, FILE **file){
	assert(pont);

	// O número de aviões recebe um número de 0 a 3
	// Chegam no máximo 3 aviões na fila por vez
	*nAvioes = rand()%4;

	// A quantidade de combustivel recebe um número de 0 a 18
	// Acrescenta-se 2 em cada combustível para não ter nenhum avião com combustível igual a 0
	qtdCombustivel = rand()%19;
	qtdCombustivel = qtdCombustivel + 2;

	int aux = *nAvioes;

	// Printa quantos aviões chegaram para pousar
	if(aux == 0){
		fprintf(*file,"Nenhum avião chegou na prateleira %d\n\n",nPrateleira);
		return;
	}
	else if(aux == 1)
		fprintf(*file,"%d avião acabou de chegar na prateleira %d\n",aux,nPrateleira);
	else
		fprintf(*file,"%d aviões acabaram de chegar na prateleira %d\n",aux,nPrateleira);

	// Insere a quantidade de aviões que chegaram na prateleira
	while((aux) > 0){
		
		// Não deixa o avião receber o mesmo id e a mesma quantidade de combustível
		if(aux == 1){
			id=id+2;
			qtdCombustivel = rand()%19;
			qtdCombustivel = qtdCombustivel + 2;
		}
		if(aux == 2){
			id=id+2;
			qtdCombustivel = 0;
			qtdCombustivel = rand()%19;
			qtdCombustivel = qtdCombustivel + 2;
		}

		// Insere o avião na fila de pouso
		if(*pont == NULL){
			*pont = (noAviao *) malloc(sizeof(noAviao));
			if(*pont != NULL){
				(*pont)->id = id;
				(*pont)->qtdCombustivel = qtdCombustivel;
				(*pont)->prox = *pont;

			}
		}else{
			noAviao *aux = (noAviao *) malloc(sizeof(noAviao));
			aux->id = id;
			aux->qtdCombustivel = qtdCombustivel;
			aux->prox = (*pont)->prox;
			(*pont)->prox = aux;
		}

		aux = aux - 1;
	}

	noAviao *aux2 = *pont;

	// Remove uma quantidade de combustível para cada inserção
	// E prioriza quem tem o combustível igual a 2
	do{
		aux2->qtdCombustivel = aux2->qtdCombustivel - 1;
		if(aux2->prox->qtdCombustivel == 2){
			removePrioridade(aux2,file);
		}
		aux2 = aux2->prox;
	}while(aux2 != (*pont));

	fprintf(*file,"Prateleira %d:\n",nPrateleira);
	printaFila(*pont,file);
}

void removeFila(noAviao **pont, int nPrateleira, FILE **file){
	assert(pont);

	if(*pont == NULL) return;
	
	noAviao *aux = *pont;
	noAviao *pontPrim = (*pont)->prox;
	noAviao *pontPenult = (*pont)->prox;

	// Remove uma quantidade de combustível para cada inserção
	// E prioriza quem tem o combustível igual a 2
	do{
		aux->qtdCombustivel = aux->qtdCombustivel - 1;
		if(aux->prox->qtdCombustivel == 2){
			removePrioridade(aux, file);
		}
		aux = aux->prox;
	}while(aux != (*pont));


	// Remove o avião da fila (pousa o avião)
	if(pontPrim->prox != pontPrim){
		while(pontPenult->prox != *pont){
			pontPenult = pontPenult->prox;
		}
		free(*pont);
		fprintf(*file,"Avião ID:%d da prateleira %d pousou com sucesso!\n\n",((*pont)->id), nPrateleira);
		*pont = pontPenult;
		pontPenult->prox = pontPrim;
	}else{
		free(*pont);
		fprintf(*file,"Avião ID:%d da prateleira %d pousou com sucesso!\n\n",((*pont)->id), nPrateleira);
		*pont = NULL;
	}
}

void printaFila(noAviao *pont, FILE **file){
	if(pont == NULL){
		fprintf(*file,"Não há aviões na fila de pouso!\n");
		
	}else{
		noAviao *aux = pont;
		while(aux->prox != pont){
			aux = aux->prox;
			fprintf(*file,"ID: %d\tCombustível restante: %d\n", aux->id, aux->qtdCombustivel);
		}
		fprintf(*file,"ID: %d\tCombustível restante: %d\n", pont->id, pont->qtdCombustivel);
	}
	fprintf(*file,"\n");
}

void removePrioridade(noAviao *pont, FILE **file){
	
}