#ifndef BIB_H
#include <stdio.h>
#define BIB_H

typedef struct noAviao{
	int id;
	int qtdCombustivel;
	struct noAviao *prox;
}noAviao;

void insereFila(noAviao **pont, int id, int qtdCombustivel, int *nAvioes, int nPrateleira, FILE **file);
void removeFila(noAviao **pont, int nPrateleira, FILE **file);
void removePrioridade(noAviao *pont, FILE **file);
void decolaAviao();
void printaFila(noAviao *pont, FILE **file);

#endif