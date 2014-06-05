#include "StringOps.h"
#include "Struct.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv)
{
    int *vetor, *acabou = 0;
	unsigned char carac;
	int entradaCorreta = TRUE;

	No *teste;
	Celula *cabCelula;

	FILE *entrada = NULL;
    vetor = malloc(128*sizeof(int)); /*existem 127 caracteres na tabela ASCII, eh alocado 128 posicoes pois existe a posicao 0*/
	
	if(argc - 1 > 0)
	{
		entrada = leEntrada(argv[1]);
	} else {
		entradaCorreta = FALSE;
		printf("\nModo de utilização:\n\n");
		printf("	ep3 <arquivo_para_compactacao>\n\n");
	}
	
	if(entradaCorreta)
	{
		while(TRUE)
    	{
			if((fscanf(entrada, "%c", &carac)) != EOF)
            {
				vetor[carac]++;
	        }
	        else break;
	    }

		cabCelula = criaListaCelula(vetor);
		imprimeCelula(cabCelula);

		teste = criaNo(cabCelula, acabou);
	}
	

    return 0;
}