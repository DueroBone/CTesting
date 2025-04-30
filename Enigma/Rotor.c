#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rotor.h"

const static int rotorWirings[][26] = {
    // E K M F L G D Q V Z N T O W Y H X U S P A I B R C J
    {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9}, // Rotor I
    // A J D K S I R U X B L H W T M C Q G Z N P Y F V O E
    {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4}, // Rotor II
    // B D F H J L C P R T X V Z N Y E I W G A K M U S Q O
    {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14}, // Rotor III
};

const static int rotorNotchPositions[] = {16, 4, 21}; // q e v

/** Passes an int through the rotor, inputs should be from 0-26, not char values */
int getRotorOutput(Rotor *rotor, int input, int isReverse)
{
  int adjustedInput = (input + rotor->position) % 26;

  if (adjustedInput < 0)
  {
    printf("Adjusted input is negative: %d  in:%d  pos:%d\n", adjustedInput, input, rotor->position);
  }

  int output = rotor->wirings[adjustedInput][isReverse];

  output = (output - rotor->position) % 26;

  return output;
}

void setRotorOffset(Rotor *rotor, int position)
{
  rotor->position = position;
}

void rotateRotor(Rotor *rotor)
{
  rotor->position = (rotor->position + 1) % 26;
  rotor->isNotch = (rotor->position == rotor->notchPositon);
}

char *rotorToString(Rotor *rotor)
{
  char *result = malloc((26 * 3 + 5) * sizeof(char)); // TODO: Check how large this needs to be
  if (result == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  int i;
  int j = 0;
  for (i = 0; i < (26 * 3); i += 3)
  {
    result[i] = rotorWirings[rotor->rotorNum][j] + 'A';
    result[i + 1] = ',';
    result[i + 2] = ' ';
    j++;
  }
  char offsetStr[3];
  snprintf(offsetStr, sizeof(offsetStr), "%d", rotor->position);
  result[i] = offsetStr[0];
  result[i + 1] = offsetStr[1];
  result[i + 2] = '\0'; // Null-terminate the string
  return result;
}

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

  rotor->rotorNum = rotorNum;
  rotor->position = startingOffset % 26;
  rotor->notchPositon = rotorNotchPositions[rotorNum - 1];
  for (int i = 0; i < 26; i++)
  {
    rotor->wirings[i][0] = rotorWirings[rotorNum - 1][i];
    for (int j = 0; j < 26; j++)
    {
      if (i == rotorWirings[rotorNum - 1][j])
      {
        rotor->wirings[i][1] = rotorWirings[rotorNum - 1][j];
        break;
      }
    }
  }

  return rotor;
}

void freeRotor(Rotor *rotor)
{
  free(rotor);
  rotor = NULL;
}