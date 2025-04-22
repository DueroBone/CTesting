#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rotor.h"

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

/** Passes an int through the rotor, inputs should be from 0-26, not char values */
int getRotorOutput(Rotor *rotor, int input)
{
  // Check if the input is within the valid range
  if (input < 0 || input > 25)
  {
    return -1; // Invalid input
  }

  // Apply the position to the input
  int adjustedInput = mod((input + rotor->position));

  // Get the output from the rotor's wirings
  int output = rotor->wirings[adjustedInput];

  // Adjust the output back by subtracting the position
  output = mod((output - rotor->position));

  return output;
}

void setRotorOffset(Rotor *rotor, int position)
{
  // Set the rotor's position
  rotor->position = mod(position);
}

void rotateRotor(Rotor *rotor)
{
  // Rotate the rotor by incrementing the position
  rotor->position = mod((rotor->position + 1));
}

char *rotorToString(Rotor *rotor)
{
  char *result = malloc(100 * sizeof(char)); // Allocate memory for the string
  int i;
  int j = 0;
  for (i = 0; i < (26 * 3); i += 3)
  {
    result[i] = rotor->wirings[j] + 'A';
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