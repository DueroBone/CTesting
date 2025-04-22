#include "EnigmaMachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

EnigmaMachine *generateMachine(Rotor *rotor1, Rotor *rotor2, Rotor *rotor3, Reflector *reflector, Plugboard *plugboard)
{
  EnigmaMachine *machine = malloc(sizeof(EnigmaMachine));
  if (machine == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  machine->rotors[0] = rotor1;
  machine->rotors[1] = rotor2;
  machine->rotors[2] = rotor3;
  return machine;
}

void setRotorPositions(EnigmaMachine *machine, int pos1, int pos2, int pos3)
{
  if (pos1 < 0 || pos1 > 25 ||
      pos2 < 0 || pos2 > 25 ||
      pos3 < 0 || pos3 > 25)
  {
    fprintf(stderr, "Invalid rotor positions\n");
    exit(EXIT_FAILURE);
  }
  machine->rotors[0]->position = pos1;
  machine->rotors[1]->position = pos2;
  machine->rotors[2]->position = pos3;
}
char runEnigmaMachine(EnigmaMachine *machine, char *input)
{
}
void freeEnigmaMachine(EnigmaMachine *machine)
{
}