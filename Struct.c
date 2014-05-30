#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Struct.h"

#define NEW_LINE 10
#define SPACE 32


Celula *criaListaCelula(int *vetor)
{
	int i;
	Celula *cabCelula = malloc(sizeof(Celula));
	for(i=33; i<=127; i++) /*ignora simbolos especiais*/
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
        if(vetor[i] != 0)	/*precisamos tratar as ocorrencias de NEW_LINE e SPACE*/
		{
			insereCelulaInicial(cabCelula, i, vetor[i]);
		}
	}
	return cabCelula;
}

void insereCelulaInicial(Celula *cabCelula, char caracter, int ocorre)
{
	Celula *new = malloc(sizeof(Celula));
	char *s = malloc(2 * sizeof(char));

	switch(caracter)
	{
		case NEW_LINE:
		new->carac = "NEW_LINE";
		break;

		case SPACE:
		new->carac = "SPACE";
		break;

		default:
		s[0] = caracter;
		s[1] = '\0';
		new->carac = s;
	}	
	new->ocorrencias = ocorre;
	printf("Caracter as ser inserido: %d\n", caracter);
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


void insereCelula(Celula *cabCelula, char *caracter, int ocorre) /*funcao responsavel pela insercao de uma nova celula, apos duas celulas 
																 serem unidas em um no*/
{
	Celula *new = malloc(sizeof(Celula));

	new->carac = caracter; /*remover apos tratarmos os caracteres especiais*/
	new->ocorrencias = ocorre;
	/*printf("Caracter as ser inserido: %d\n", caracter);*/
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
	Celula *temp = cabCelula->prox; /*nao eh necessario verificar se temp eh NULL, pois a funcao q ira invoca-la jah verifica isso*/
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
			if(imprime->carac <= 33)
				printf("Dados da celula atual: Caracter: %s, Numero de ocorrencias: %d\n", imprime->carac, imprime->ocorrencias);
			else
				printf("Dados da celula atual: Caracter: %c, Numero de ocorrencias: %d\n", imprime->carac, imprime->ocorrencias);
			printf("FINAL DO FOR********************\n");
			/*usleep(360000);*/
		}
		/*printf("SAI DO FOR*******************\n");*/
	}	
}

No *criaNo(Celula *cabCelula, int *flagAcabou)
{
	No *nova;
	Celula *c0, *c1;
	if(cabCelula->prox != NULL)
	{
		c0 = removeMenor(cabCelula);
		if(cabCelula->prox != NULL)
		{
			c1 = removeMenor(cabCelula);
		}
		else
		{
			flagAcabou = 1;
		}
	}
	else
	{
		printf(stderr,"Lista vazia************************************\n");
	}

	printf("c0->carac: %s, c1->carac: %s\n", c0->carac, c1->carac);

	concatenaStrings(c0->carac, c1->carac); /*atribui os valores do NO criado*/
	nova->carac = c0->carac;
	nova->probabilidade = c0->ocorrencias + c1->ocorrencias;	

	insereCelula(cabCelula, nova->carac, nova->probabilidade); /*reinsere os dados do NO criado na lista encadeada*/

	printf("Dados do NO criado: %s, %d\n", nova->carac, nova->probabilidade);
	return nova;	
}