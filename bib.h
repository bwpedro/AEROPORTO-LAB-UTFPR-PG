#ifndef BIB_H
#define BIB_H

typedef struct noAviao{
	int id;
	int qtdTempo;
	struct noAviao *prox;
}noAviao;

void insereFila(noAviao **pont, int id, int qtdTempo);
void removeFila(noAviao **pont);
void printaFila(noAviao *pont);

#endif