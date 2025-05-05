#include "stdlib.h"
#include "stdio.h"
#include <ctype.h>

char *intArrToCharArr(int *input, int length)
{
  char *output = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++)
  {
    if (input[i] == -1)
    {
      output[i] = ' ';
      continue;
    }
    output[i] = input[i] + 'A';
  }
  output[length] = '\0';
  return output;
}

/** Removes the null terminator, copies to heap */
int *charArrToIntArr(char *input, int length)
{
  int *output = malloc(sizeof(int) * length);
  if (output == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  for (int i = 0; i < length; i++)
  {
    if (input[i] == ' ')
    {
      output[i] = -1;
      continue;
    }
    output[i] = (((toupper(input[i]) - 'A') % 26) + 26) % 26;
  }
  return output;
}