#include "StringOps.h"

FILE *leEntrada (char *nomeArquivo)
{
    FILE *entrada;
    entrada = fopen(nomeArquivo, "r");
    if(entrada == NULL)
    {
        fprintf(stderr, "Nao consegui ler o arquivo!");
        exit(-1);
    }
    return entrada;
}

/*
  mallocSafe: testa o ponteiro devolvido por malloc
 */
void * mallocSafe (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n\n");
    exit(-1);
  }
  return pt;
}


char *concatenaStrings(char *original, char *add)
{
  char *novaString;
  int i = 0;
  printf("%d\n", i);
  printf("ori: %s, add: %s\n", original, add);

  int tamanho = strlen(original) + strlen(add);
  printf("Tamanho: %d\n", tamanho);
  novaString = malloc(tamanho*sizeof(char));

printf("passei\n");
   while(*original != '\0')
   {

      novaString[i] = original[i];
      printf("novaString: %d, ori: %d\n", novaString[i], original[i]);
      i++;
   }      
 printf("ok ate aqui\n");
   while(*add != '\0')
   {
      novaString[i] = add++;
      i++;
   }

   novaString[i] = '\0';


   printf("String gerada: ");
   for(i=0; i< tamanho; i++)
   {
    printf(" %d", novaString[i]);
   }

   printf("\n");

   return novaString;
}