#ifndef BIB_H
#include <stdio.h>
#define BIB_H

typedef struct noAviao{
	int id;
	int qtdCombustivel;
	struct noAviao *prox;
}noAviao;

void insereFila(noAviao **pont, int id, int qtdCombustivel, int *nAvioes, int nPrateleira, FILE **file, int *prioridade);
void removeFila(noAviao **pont, int nPrateleira, FILE **file, int *prioridade);
void removePrioridade(noAviao **pontPrim, noAviao **pont, FILE **file);
void decolaAviao(noAviao **pont, FILE **file);
void printaFila(noAviao *pont, FILE **file, int nPrateleira);

#endif