#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Struct.h"


Celula *criaListaCelula(int *vetor)
{
	int i; 
	char c;
	Celula *cabCelula = malloc(sizeof(Celula));
	Celula *aux;
	Celula *nova = malloc(sizeof(Celula));
	Celula *aux1 = malloc(sizeof(Celula));
	Celula *aux2 = malloc(sizeof(Celula));
	cabCelula->ocorrencias = 42;
	cabCelula->carac = 'A';
	aux1->ocorrencias = 43;
	aux1->carac = 'B';
	aux2->ocorrencias = 44;	
	aux2->carac = 'C';
	cabCelula->prox = aux1;
	cabCelula->prox->prox = aux2;
	for(i=1; i<=127; i++)
    {
		/*if(i == 10 && vetor[i] != 0)
		{
			printf("Numero de ocorrencias do caracter NEW_LINE: %d\n", vetor[i]);
		}
		else
		if(i == 32 && vetor[i] != 0)
		{
			printf("Numero de ocorrencias do caracter SPACE: %d\n", vetor[i]);
		}
		else*/
        if(i != 10 && i != 32 && vetor[i] != 0)	/*precisamos tratar as ocorrencias de NEW_LINE e SPACE*/
		{		
			c = i;
			nova->carac = c;
			nova->ocorrencias = vetor[i];
			nova->prox = NULL;
			usleep(15000);/*1500000*/
			if(cabCelula->prox == NULL) /*lista vazia*/
			{
				cabCelula->prox = nova;
				printf("Inserido primeiro elemento da lista\n");
				printf("Celula inserida: %c, %d\n", nova->carac, nova->ocorrencias);
			}
			else
	    	{		        
		        aux = cabCelula->prox; /*aux deve estar com carac = 'B'*/
				printf("ELSE\n");
		        while(aux->prox != NULL)
		        {
					printf("WHILE\n");
					printf("Dados da celula atual: %c %d\n",aux->carac, aux->ocorrencias);
		            aux = aux->prox;		           
		        }
		        aux->prox = nova;
		        printf("Celula inserida: %c, %d\n", nova->carac, nova->ocorrencias);
    		}
			printf("saiu do else\n");
			printf("**************************************************************\n");
			imprimeCelula(cabCelula);
			printf("**************************************************************\n");
		}
	}

	return cabCelula;
}


void imprimeCelula(Celula *cabCelula)
{
	Celula *imprime;
	printf("Entrou no imprime\n");
	usleep(1500000);
	if(cabCelula != NULL)
	{
		for(imprime = cabCelula; imprime != NULL; imprime = imprime->prox)
		{
			printf("Dados da celula atual: Caracter: %c, Numero de ocorrencias: %d\n", imprime->carac, imprime->ocorrencias);
			usleep(150000);
		}
	}	
}