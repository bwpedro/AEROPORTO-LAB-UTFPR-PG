#include "bib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void insereFila(noAviao **pont, int id, int qtdCombustivel, int *nAvioes, int nPrateleira, FILE **file, int *prioridade){
	assert(pont);
	assert(file);

	/* O número de aviões para pousar recebe um número de 0 a 3
	 * Chegam no máximo 3 aviões na fila de pouso por vez
	 * O número de aviões para decolar recebe um número de 0 a 1
	 * Chega no máximo 1 avião na fila de pouso por vez
	 */
	if(nPrateleira == 5)
		*nAvioes = rand()%2;
	else
		*nAvioes = rand()%4;

	/* A quantidade de combustível recebe um número de 0 a 18
	   Acrescenta-se 2 em cada combustível para não ter nenhum avião com combustível igual a 0 */
	qtdCombustivel = rand()%19 + 2;

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
			qtdCombustivel = rand()%19 + 2;
		}
		if(aux == 2){
			id=id+2;
			qtdCombustivel = rand()%19 + 2;
		}

		// Insere o avião na fila de pouso ou decolagem
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

	fprintf(*file,"Prateleira %d:\n",nPrateleira);
	printaFila(*pont,file,nPrateleira);

	/* Remove uma quantidade de combustível para cada inserção
	   E prioriza quem tem o combustível igual a 2 */
	if(nPrateleira != 5){
		noAviao *aux2 = *pont;
		do{
			aux2->qtdCombustivel = aux2->qtdCombustivel - 1;
			if(aux2->prox->qtdCombustivel <= 2){
				removePrioridade(pont,&aux2,file);
				*prioridade = *prioridade + 1;
				return;
			}else 
				aux2 = aux2->prox;
		}while(aux2 != (*pont));
	}
}

void removeFila(noAviao **pont, int nPrateleira, FILE **file, int *prioridade){
	assert(pont);
	assert(file);

	if(*pont == NULL) return;
	
	noAviao *aux = *pont;
	noAviao *pontPrim = (*pont)->prox;
	noAviao *pontPenult = (*pont)->prox;

	/* Remove uma quantidade de combustível para cada inserção
	   E prioriza quem tem o combustível igual a 2 */
	do{
		aux->qtdCombustivel = aux->qtdCombustivel - 1;
		if(aux->prox->qtdCombustivel <= 2){
			removePrioridade(pont, &aux, file);
			*prioridade = *prioridade + 1;
			return;
		}else
			aux = aux->prox;
	}while(aux != (*pont));


	// Remove o avião da fila (pousa o avião)
	if(pontPrim->prox != pontPrim){
		while(pontPenult->prox != *pont){
			pontPenult = pontPenult->prox;
		}
		free(*pont);
		if(nPrateleira != 0)
			fprintf(*file,"Avião ID:%d da prateleira %d pousou!\n\n",((*pont)->id), nPrateleira);
		*pont = pontPenult;
		pontPenult->prox = *pont;
	}else{
		free(*pont);
		if(nPrateleira != 0)
			fprintf(*file,"Avião ID:%d da prateleira %d pousou!\n\n",((*pont)->id), nPrateleira);
		*pont = NULL;
	}
}

void decolaAviao(noAviao **pont, FILE **file){
	assert(pont);
	assert(file);

	if(*pont == NULL) return;

	noAviao *pontPrim = (*pont)->prox;
	noAviao *pontPenult = (*pont)->prox;

	// Remove o avião da fila (decola o avião)
	if(pontPrim->prox != pontPrim){
		while(pontPenult->prox != *pont){
			pontPenult = pontPenult->prox;
		}
		free(*pont);
		fprintf(*file,"Avião ID:%d decolou!\n\n",((*pont)->id));
		*pont = pontPenult;
		pontPenult->prox = pontPrim;
	}else{
		free(*pont);
		fprintf(*file,"Avião ID:%d decolou!\n\n",((*pont)->id));
		*pont = NULL;
	}
}

void printaFila(noAviao *pont, FILE **file, int nPrateleira){
	assert(file);
	
	if(pont == NULL){
		if(nPrateleira == 5)
			fprintf(*file,"Na prateleira %d todos os aviões decolaram!\n",nPrateleira);
		else
			fprintf(*file,"Na prateleira %d todos os aviões pousaram!\n",nPrateleira);
	}else{
		noAviao *aux = pont;
		while(aux->prox != pont){
			aux = aux->prox;
			fprintf(*file,"ID: %d\tCombustível: %d\n", aux->id, aux->qtdCombustivel);
		}
		fprintf(*file,"ID: %d\tCombustível: %d\n", pont->id, pont->qtdCombustivel);
	}
	fprintf(*file,"\n");
}

void removePrioridade(noAviao **pontPrim, noAviao **pont, FILE **file){
	assert(file);
	assert(pont);

	if(*pont == NULL) return;

	// Se o a avião for o único na fila
	if((*pont) == (*pont)->prox){
		free(*pont);
		*pont = NULL;
		*pontPrim = NULL;
		return;
	}

	// Se o avião for o primeiro da fila
	if(*pontPrim == (*pont)->prox){
		free(*pontPrim);
		*pontPrim = *pont;
		(*pont)->prox = *pont;
		return;
	}
	
	// Caso genérico
	free((*pont)->prox);
	(*pont)->prox = *pontPrim;

	fprintf(*file,"Um avião com prioridade nessa prateleira acabou de pousar\n\n");
}