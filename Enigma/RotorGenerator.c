#include "Rotor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int rotorWirings[3][26] = {
    // E K M F L G D Q V Z N T O W Y H X U S P A I B R C J
    {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9}, // Rotor I
    // A J D K S I R U X B L H W T M C Q G Z N P Y F V O E
    {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4}, // Rotor II
    // B D F H J L C P R T X V Z N Y E I W G A K M U S Q O
    {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14}, // Rotor III
};

Rotor *generateRotor(int rotorNum, int startingOffset)
{
  Rotor *rotor = malloc(sizeof(Rotor));
  if (rotor == NULL)
  {
    fprintf(stderr, "Memory allocation failed:\n   Generating rotor %d at position %d\n", rotorNum, startingOffset);
    return NULL;
  }
  if (rotorNum < 1 || rotorNum > 3)
  {
    fprintf(stderr, "Invalid rotor number: %d\n", rotorNum);
    free(rotor);
    return NULL;
  }
  rotor->position = startingOffset % 26;
  for (int i = 0; i < 26; i++)
  {
    rotor->wirings[i] = rotorWirings[rotorNum - 1][i];
  }

  return rotor;
}