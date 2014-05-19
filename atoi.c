#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *vetor;
    int i;
    char car;
    vetor = malloc(127*sizeof(int));
    for(i=0; i< 5; i++)
    {
        printf("Digite um character:");
        scanf("%c", &car);
        vetor[car]++;
    }
    for(i=0; i<127; i++)
    {
        if(vetor[i] != 0)
            printf("Valor do indice %d: %d\n",i, vetor[i]);
    }

    return 0;
}

