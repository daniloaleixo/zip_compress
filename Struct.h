#ifndef _STRUCT_H
#define _STRUCT_H

typedef struct celula {
	char *carac; /*armazena o caracter*/
	int ocorrencias; /*armazena o numero de vezes que o caracter eh lido*/
	struct celula *prox; 
} Celula;

typedef struct no {
	char *carac;
	int probabilidade; /*valor da soma dos nos inferiores*/
	struct no *esq, *dir; /*filhos esq e dir*/
} No;

Celula *criaListaCelula(int *vetor); /*recebe um array como parametro e insere numa lista encadeada cada caracter com numero de ocorrencias diferente de zero*/
void insereCelulaInicial(Celula *cabCelula, char caracter, int ocorre);
void insereCelula(Celula *cabCelula, char *caracter, int ocorre);
Celula *removeMenor(Celula *cabCelula);
void imprimeCelula(Celula *cabCelula);
No *criaNo(Celula *cabCelula, int *flagAcabou); 

#endif