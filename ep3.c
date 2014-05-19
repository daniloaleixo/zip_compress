#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StringOps.h"

#define TRUE 1
#define FALSE 0

FILE *leEntrada (char *nomeArquivo);

int main(int argc, char **argv)
{
    int *vetor;
    int i, cont=0;
	char carac;
	FILE *entrada;
    vetor = malloc(128*sizeof(int));
	
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
	printf("Numero de caracteres lidos: %d\n", cont);	
	
	    for(i=1; i<=128; i++)
    {
        if(vetor[i] != 0)
            printf("Valor do indice %d: %d\n",i, vetor[i]); /*arrumar indice*/
    }
    return 0;
}
