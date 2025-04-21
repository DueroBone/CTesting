#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "RotorGenerator.h"
#include "Rotor.h"

int main()
{
  // Generate rotors
  Rotor *rotor1 = generateRotor(1, 0);
  Rotor *rotor2 = generateRotor(2, 0);
  Rotor *rotor3 = generateRotor(3, 0);

  // Print rotor wirings
  printf("Rotor I: %s\n", rotorToString(rotor1));
  printf("Rotor II: %s\n", rotorToString(rotor2));
  printf("Rotor III: %s\n", rotorToString(rotor3));

  // Free allocated memory
  free(rotor1);
  free(rotor2);
  free(rotor3);

  return 0;
}