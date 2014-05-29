#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Struct.h"


Celula *criaListaCelula(int *vetor)
{
	int i;
	Celula *cabCelula = malloc(sizeof(Celula));
	printf("*********************************************************************************************************\n");
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
			insereCelula(cabCelula, i, vetor[i]);
		}
	}
	return cabCelula;
}

void insereCelula(Celula *cabCelula, char caracter, int ocorre)
{
	Celula *new = malloc(sizeof(Celula));

	new->carac = caracter;
	new->ocorrencias = ocorre;
	if(cabCelula->prox == NULL) /*lista vazia*/
    {
        cabCelula->prox = new;
    }
    else /*como a lista nao esta vazia, insere-se a celula na lista em ordem crescente*/
    {
    	Celula *aux = cabCelula->prox;
    	if(new->ocorrencias <= aux->ocorrencias) /*elemento a ser inserido eh menor que o primeiro elemento da lista*/
    											 /*logo ele deve se tornar o primeiro elemento*/
    	{
    		new->prox = aux;
    		cabCelula->prox = new;
    	}
    	else
    	{    		
    		Celula *ant = aux;
    		while(new->ocorrencias > aux->ocorrencias && aux->prox != NULL)
    		{
    			ant = aux;
    			aux = aux->prox;
    		}
    		ant->prox = new;
    		new->prox = aux;
    	}
    }
}

Celula *removeMenor(Celula *cabCelula) /*como a lista esta ordenada em ordem crescente, basta remover o primeiro elemento da lista*/
{
	Celula *temp = cabCelula->prox;
	cabCelula->prox = temp->prox;
	return temp;
}

void imprimeCelula(Celula *cabCelula)
{
	Celula *imprime;
	if(cabCelula != NULL)
	{
		for(imprime = cabCelula->prox; imprime != NULL; imprime = imprime->prox)
		{
			printf("Dados da celula atual: Caracter: %c, Numero de ocorrencias: %d\n", imprime->carac, imprime->ocorrencias);
		}
	}	
}