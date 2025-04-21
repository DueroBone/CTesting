#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rotor.h"

int getRotorOutput(Rotor *rotor, int input)
{
  // Check if the input is within the valid range
  if (input < 0 || input > 25)
  {
    return -1; // Invalid input
  }

  // Apply the offset to the input
  int adjustedInput = mod((input + rotor->offset));

  // Get the output from the rotor's wirings
  int output = rotor->wirings[adjustedInput];

  // Adjust the output back by subtracting the offset
  output = mod((output - rotor->offset));

  return output;
}

/** Input must be in the range of -25 to 51 */
int mod(int num)
{
  if (num < 0)
  {
    return (num + 26);
  }
  else if (num > 25)
  {
    return (num - 26);
  }
  return num;
}

void setRotorOffset(Rotor *rotor, int offset)
{
  // Set the rotor's offset
  rotor->offset = mod(offset);
}

void rotateRotor(Rotor *rotor)
{
  // Rotate the rotor by incrementing the offset
  rotor->offset = (rotor->offset + 1) % 26;
}

char *rotorToString(Rotor *rotor)
{
  char *result = malloc(100 * sizeof(char)); // Allocate memory for the string
  int i;
  for (i = 0; i < (26 * 3); i += 3)
  {
    result[i] = rotor->wirings[i] + 'A';
    result[i + 1] = ',';
    result[i + 2] = ' ';
  }
  char offsetStr[3];
  snprintf(offsetStr, sizeof(offsetStr), "%d", rotor->offset);
  result[i] = offsetStr[0];
  result[i + 1] = offsetStr[1];
  result[i + 2] = '\0'; // Null-terminate the string
  return result;
}