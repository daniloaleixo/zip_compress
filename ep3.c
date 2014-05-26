#include <string.h>
#include "StringOps.h"
#include "Struct.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv)
{
    int *vetor;
    int i, cont=0;
	char carac, c;
	Celula *cabCelula;
	FILE *entrada = NULL;
    vetor = malloc(128*sizeof(int)); /*existem 127 caracteres na tabela ASCII, eh alocado 128 posicoes pois existe a posicao 0*/
	
	if(argc - 1 > 0)
	{
		entrada = leEntrada(argv[1]);
	}
	
	while(TRUE)
    {
		if((fscanf(entrada, "%c", &carac)) != EOF)
            {
            cont++;
			vetor[carac]++;
            }
        else break;
    }
	/*printf("Numero de caracteres lidos: %d\n", cont);	
	
	    for(i=1; i<=127; i++)
    {
		if(i == 10 && vetor[i] != 0)
		{
			printf("Numero de ocorrencias do caracter NEW_LINE: %d\n", vetor[i]);
		}
		else
		if(i == 32 && vetor[i] != 0)
		{
			printf("Numero de ocorrencias do caracter SPACE: %d\n", vetor[i]);
		}
		else
        if(vetor[i] != 0)	
		{		
			c = i;
            printf("Numero de ocorrencias do caracter %c: %d\n",c, vetor[i]);
		}
    }*/

	cabCelula = criaListaCelula(vetor);
	imprimeCelula(cabCelula);
    return 0;
}
