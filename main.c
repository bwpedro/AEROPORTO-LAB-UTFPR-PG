#include "bib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	int selec, podeSair = 1;

	noAviao *pont = NULL;
	int id = 1;
	float qtdTempo = 0;

	do{
		printf("Selecione uma Opção:\n1- Inserir na fila.\n2- Remover na fila.\n");
		scanf("%d", &selec);

		switch(selec){
			case 1:

				insereFila(&pont, id++, qtdTempo);

				podeSair = 2;
				break;

			case 2:
				removeFila(&pont);

				podeSair = 2;
				break;

			default:
				printf("Digite uma opção válida!\n");
		}

		if(podeSair == 2){
			printf("Deseja fazer outra operação? (1-Sim / 0-Não)\n");
			scanf("%d", &podeSair);
		}
	}while(podeSair == 1);


	return 0;
}