#include "StringOps.h"
#include "Struct.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv)
{
    int *vetor, *acabou = 0;
	unsigned char carac;

	No *teste;
	Celula *cabCelula;

	FILE *entrada = NULL;
    vetor = malloc(128*sizeof(int)); /*existem 127 caracteres na tabela ASCII, eh alocado 128 posicoes pois existe a posicao 0*/
	
	if(argc - 1 > 0)
	{
		/* Lemos a entrada */
		entrada = leEntrada(argv[1]);

		/* 	Colocamos toda a informacao do arquivo no vetor "vetor"
		ate o fim do arquivo */
		while(TRUE)
    	{
			if((fscanf(entrada, "%c", &carac)) != EOF)
            {
				vetor[carac]++;
	        }
	        else break;
	    }

	    /* Criamos uma lista encadeada com o caracter e 
	       e seu numero de occorencias */
		cabCelula = criaListaCelula(vetor);
		imprimeCelula(cabCelula);

		/*teste = criaNo(cabCelula, acabou);*/
	}
	else {
		printf("\nModo de utilização:\n\n");
		printf("	ep3 <arquivo_para_compactacao>\n\n");
	}
	

    return 0;
}