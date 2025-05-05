#include "Plugboard.h"
#include <stdlib.h>
#include <stdio.h>

Plugboard generateEmptyPlugboard()
{
  Plugboard plugboard;
  for (int i = 0; i < 10; i++)
  {
    plugboard.wiring[i][0] = -1;
    plugboard.wiring[i][1] = -1;
  }
  return plugboard;
}

Plugboard generatePlugboard(int wiring[10][2])
{
  Plugboard plugboard;
  for (int i = 0; i < 10; i++)
  {
    plugboard.wiring[i][0] = wiring[i][0];
    plugboard.wiring[i][1] = wiring[i][1];
  }
  return plugboard;
}

void freePlugboard(Plugboard *plugboard)
{
  if (plugboard != NULL)
  {
    free(plugboard);
  }
}

int getPlugboardOutput(Plugboard *plugboard, int input)
{
  for (int i = 0; i < 10; i++)
  {
    if (plugboard->wiring[i][0] == -1 || plugboard->wiring[i][1] == -1)
    {
      return input;
    }
    if (plugboard->wiring[i][0] == input)
    {
      return plugboard->wiring[i][1];
    }
    else if (plugboard->wiring[i][1] == input)
    {
      return plugboard->wiring[i][0];
    }
  }
  return input;
}