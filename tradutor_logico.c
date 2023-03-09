#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void insertion_sort(char **p, int size, int *resp)
{
  int i, j, carta;
  char *key;
  for (i = 1; i < size; i++)
  {
    carta = resp[i];
    key = p[i];
    j = i - 1;
    while ((j >= 0) && (p[j] > key))
    {
      p[j + 1] = p[j];
      resp[j + 1] = resp[j];
      j--;
    }
    p[j + 1] = key;
    resp[j + 1] = carta;
  }
}

void le(char *frase)
{
  printf("Entre com a frase, ou <fim> para sair:\n");
  fgets(frase, 200, stdin);
}

int operadores(char *frase, char **p, int *resp)
{
  int i;
  int cont = 0;
  int *aux;
  int max = strlen(frase);
  char *acha;

  // possibilidades do Bicondicional;
  acha = strstr(frase, "se e somente se ");
  while (acha != NULL && max > 0)
  {
    strncpy(acha, "               ", 15);
    p[cont] = acha;
    resp[cont] = 5;
    max = strlen(acha);
    acha = strstr(acha + 1, "se e somente se ");
    cont++;
  }

  // Posibilidades do e
  acha = strstr(frase, " e ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 1;
    max = strlen(acha);
    acha = strstr(acha + 1, " e ");
    cont++;
  }
  acha = strstr(frase, " E ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 1;
    max = strlen(acha);
    acha = strstr(acha + 1, " E ");
    cont++;
  }
  acha = strstr(frase, " mas não");
  while (acha != NULL && max > 0)
  {
    strncpy(acha, "    ", 4);
    p[cont] = acha;
    resp[cont] = 1;
    // cont ++;
    // resp[cont]=3;
    max = strlen(acha);
    acha = strstr(acha + 1, " mas não");
    cont++;
  }
  // possibilidades do ou;
  acha = strstr(frase, " ou ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 2;
    max = strlen(acha);
    acha = strstr(acha + 1, " ou ");
    cont++;
  }
  acha = strstr(frase, " Ou ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 2;
    max = strlen(acha);
    acha = strstr(acha + 1, " Ou ");
    cont++;
  }
  // possibilidades do Não;
  acha = strstr(frase, " não ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 3;
    max = strlen(acha);
    acha = strstr(acha + 1, " não ");
    cont++;
  }
  acha = strstr(frase, "Não ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 3;
    max = strlen(acha);
    acha = strstr(acha + 1, "Não ");
    cont++;
  }
  acha = strstr(frase, "NÃO ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 3;
    max = strlen(acha);
    acha = strstr(acha + 1, "NÃO ");
    cont++;
  }
  // possibilidades do Implica;
  acha = strstr(frase, ", então ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 4;
    max = strlen(acha);
    acha = strstr(acha + 1, ", então ");
    cont++;
  }
  acha = strstr(frase, ",então ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 4;
    max = strlen(acha);
    acha = strstr(acha + 1, ",então ");
    cont++;
  }
  acha = strstr(frase, ", logo ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 4;
    max = strlen(acha);
    acha = strstr(acha + 1, ", logo ");
    cont++;
  }
  acha = strstr(frase, ",logo ");
  while (acha != NULL && max > 0)
  {
    p[cont] = acha;
    resp[cont] = 4;
    max = strlen(acha);
    acha = strstr(acha + 1, ",logo ");
    cont++;
  }

  return cont;
}

int atomica(int *resp, int *final, int tam)
{
  int i, j, k;
  k = 77;
  i = 0;
  j = i;
  if (resp[i] == 3)
  {
    final[j] = resp[i];
    j++;
    final[j] = k;
    j++;
    k++;
  }
  else
  {
    final[j] = k;
    j++;
    k++;
    final[j] = resp[i];
    j++;
    final[j] = k;
    j++;
    k++;
  }
  for (i = 1; i < tam; i++)
  {
    if (i < tam - 2 && (resp[i] == 4 || resp[i] == 5))
    {
      if (resp[i + 1] == 3)
      {
        final[j] = resp[i];
        j++;
      }
      else
      {
        final[j] = resp[i];
        j++;
        final[j] = k;
        j++;
        k++;
      }
    }
    else if (i < tam - 1 && (resp[i] == 1 || resp[i] == 2))
    {
      if (resp[i + 1] == 3)
      {
        final[j] = resp[i];
        j++;
      }
    }
    else
    {
      final[j] = resp[i];
      j++;
      final[j] = k;
      j++;
      k++;
    }
  }
  return j;
}

int procura(int *array, int tam, int busca)
{
  int i;
  for (i = 0; i < tam; i++)
  {
    if (array[i] == busca)
    {
      return i;
    }
  }
  return -1;
}

void printa2(int *final, int n)
{
  int i, implica, bimplica;
  implica = procura(final, n, 4);
  bimplica = procura(final, n, 5);
  for (i = 0; i < n; i++)
  {
    if (implica != -1 || bimplica != -1)
    {
      if (i == 0)
      {
        printf("( ");
      }
    }
    if (final[i] > 5)
    {
      printf("%c ", final[i]);
    }
    else
    {
      switch (final[i])
      {
      case 1:
        printf("^ ");
        break;

      case 2:
        printf("v ");
        break;

      case 3:
        printf("~ ");
        break;

      case 4:
        printf(") => ( ");
        break;

      case 5:
        printf(") <=> ( ");
        break;

      case 6:
        printf("^");
        printf(" ~");
        break;
      }
    }
    if (implica != -1 || bimplica != -1)
    {
      if (i == n - 1)
      {
        printf(")");
      }
    }
  }
  printf("\n");
}

int main()
{
  int tam, i, marco, n, junto;
  int cont = 1;
  char *frase;
  int *resp, *atom;
  char *p[256];
  frase = (char *)malloc(256 * sizeof(char));
  le(frase);
  while (strstr(frase, "fim") == NULL)
  {
    tam = operadores(frase, p, resp);
    if (tam > 0)
    {
      insertion_sort(p, tam, resp);
      int final[2 * tam];
      n = atomica(resp, final, tam);
      printf("A equivalência lógica segue abaixo \n");
      printa2(final, n);
    }
    else
    {
      printf("Digite uma sentença válida\n");
    }
    le(frase);
  }

  free(frase);
  return 0;
}