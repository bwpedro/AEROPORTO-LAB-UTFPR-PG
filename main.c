#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"

int main(){
	
	FILE *file;
	file = fopen("relatorio.txt", "w");

	srand(time(NULL));

	// Cria um ponteiro para cada prateleira
	noAviao *prateleira1 = NULL;
	noAviao *prateleira2 = NULL;
	noAviao *prateleira3 = NULL;
	noAviao *prateleira4 = NULL;

	// Inicializa o número de aviões de cada prateleira
	int p1nAvioes = 0;
	int p2nAvioes = 0;
	int p3nAvioes = 0;
	int p4nAvioes = 0;

	// Inicializa o id e o combustível de cada avião
	int id = 0;
	int qtdCombustivel = 0;

	// A Unidade de tempo é determinada aleatóriamente entre 1 e 100
	int undTempo = rand()%99 + 1;

	fprintf(file,"########### AEROPORTO ###########\n\n");

	fprintf(file,"O programa rodou %d unidades de tempo\n\n",undTempo);

	// Roda o programa seguindo a unidade de tempo dada pela função rand
	while(undTempo > 0){

		insereFila(&prateleira1, id=id+2, qtdCombustivel, &p1nAvioes, 1, &file);
		if((p1nAvioes) >= 1){
			removeFila(&prateleira1, 1, &file);
			removeFila(&prateleira1, 1, &file);
			p1nAvioes--;
		}

		insereFila(&prateleira2, id=id+2, qtdCombustivel, &p2nAvioes, 2, &file);
		if((p2nAvioes) >= 1){
			removeFila(&prateleira2, 2, &file);
			removeFila(&prateleira2, 2, &file);
			p2nAvioes--;
		}
		
		insereFila(&prateleira3, id=id+2, qtdCombustivel, &p3nAvioes, 3, &file);
		if((p3nAvioes) >= 1){
			removeFila(&prateleira3, 3, &file);
			removeFila(&prateleira3, 3, &file);
			p3nAvioes--;
		}

		insereFila(&prateleira4, id=id+2, qtdCombustivel, &p4nAvioes, 4, &file);
		if((p4nAvioes) >= 1){
			removeFila(&prateleira4, 4, &file);
			removeFila(&prateleira4, 4, &file);
			p4nAvioes--;
		}

		undTempo--;

		fprintf(file,"======================================\n\n");
	}

	// Printa as prateleiras no final do programa
	fprintf(file,"Prateleira 1:\n");
	printaFila(prateleira1, &file);
	fprintf(file,"Prateleira 2:\n");
	printaFila(prateleira2, &file);
	fprintf(file,"Prateleira 3:\n");
	printaFila(prateleira3, &file);
	fprintf(file,"Prateleira 4:\n");
	printaFila(prateleira4, &file);

	printf("\nPROGRAMA FINALIZADO COM SUCESSO!\nFAVOR VERIFICAR O ARQUIVO 'relatorio.txt' CRIADO.\n\n");

	fclose(file);
	return 0;
}