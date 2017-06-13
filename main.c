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
	noAviao *prateleira5 = NULL;

	// Inicializa o número de aviões de cada prateleira
	int p1nAvioes = 0;
	int p2nAvioes = 0;
	int p3nAvioes = 0;
	int p4nAvioes = 0;
	int p5nAvioes = 0;

	// Inicializa o id, o combustível de cada avião e o numero de prioridades
	int idp = 0; // Id par usado para pousco
	int idi = 1; // Id ímpar usado para decolagem
	int qtdCombustivel = 0;
	int prioridade = 0;

	// A Unidade de tempo é determinada aleatoriamente entre 1 e 100
	int undTempo = rand()%99 + 1;

	fprintf(file,"########### AEROPORTO ###########\n\n");

	fprintf(file,"O programa rodou por %d unidades de tempo\n\n",undTempo);

	// Roda o programa seguindo a unidade de tempo dada pela função rand
	while(undTempo > 0){

		insereFila(&prateleira1, idp=idp+2, qtdCombustivel, &p1nAvioes, 1, &file, &prioridade);
		if((p1nAvioes) >= 1){
			removeFila(&prateleira1, 1, &file, &prioridade);
			removeFila(&prateleira1, 1, &file, &prioridade);
			p1nAvioes--;
		}

		insereFila(&prateleira2, idp=idp+2, qtdCombustivel, &p2nAvioes, 2, &file, &prioridade);
		if((p2nAvioes) >= 1){
			removeFila(&prateleira2, 2, &file, &prioridade);
			removeFila(&prateleira2, 2, &file, &prioridade);
			p2nAvioes--;
		}
		
		insereFila(&prateleira3, idp=idp+2, qtdCombustivel, &p3nAvioes, 3, &file, &prioridade);
		if((p3nAvioes) >= 1){
			removeFila(&prateleira3, 3, &file, &prioridade);
			removeFila(&prateleira3, 3, &file, &prioridade);
			p3nAvioes--;
		}

		insereFila(&prateleira4, idp=idp+2, qtdCombustivel, &p4nAvioes, 4, &file, &prioridade);
		if((p4nAvioes) >= 1){
			removeFila(&prateleira4, 4, &file, &prioridade);
			removeFila(&prateleira4, 4, &file, &prioridade);
			p4nAvioes--;
		}

		insereFila(&prateleira5, idi=idi+2, qtdCombustivel, &p5nAvioes, 5, &file, NULL);
		if((p5nAvioes) >= 1){
			decolaAviao(&prateleira5, &file);
			p5nAvioes--;
		}

		undTempo--;

		fprintf(file,"======================================\n\n");
	}

	// inicio
	while(prateleira1 != NULL)
		removeFila(&prateleira1, 0, &file, &prioridade);
	while(prateleira2 != NULL)
		removeFila(&prateleira2, 0, &file, &prioridade);
	while(prateleira3 != NULL)
		removeFila(&prateleira3, 0, &file, &prioridade);
	while(prateleira4 != NULL)
		removeFila(&prateleira4, 0, &file, &prioridade);
	//fim

	// Printa as prateleiras no final do programa
	printaFila(prateleira1, &file, 1);
	printaFila(prateleira2, &file, 2);
	printaFila(prateleira3, &file, 3);
	printaFila(prateleira4, &file, 4);
	printaFila(prateleira5, &file, 5);

	// Printa quantas prioridades foram pousadas
	fprintf(file,"%d aviões com prioridade foram pousados.",prioridade);

	printf("\nPROGRAMA FINALIZADO COM SUCESSO!\nFAVOR VERIFICAR O ARQUIVO 'relatorio.txt' CRIADO.\n\n");

	fclose(file);
	return 0;
}