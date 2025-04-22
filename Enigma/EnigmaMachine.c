#include "EnigmaMachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

EnigmaMachine *generateMachine(Rotor *rotor1, Rotor *rotor2, Rotor *rotor3, Reflector *reflector, Plugboard *plugboard)
{
  EnigmaMachine *machine = malloc(sizeof(EnigmaMachine));
  if (machine == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
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

char *runEnigmaMachineChar(EnigmaMachine *machine, char *input)
{
  int length = strlen(input);
  for (int i = 0; i < length; i++)
  {
    input[i] = toupper(input[i]) - 'A';
  }
}

int *runEnigmaMachine(EnigmaMachine *machine, int *input)
{
  // TODO
  return 0;
}

void freeEnigmaMachine(EnigmaMachine *machine)
{
  for (int i = 0; i < 3; i++)
  {
    free(machine->rotors[i]);
  }
  free(machine);
}

void rotateRotors(EnigmaMachine *machine)
{
  rotateRotor(machine->rotors[0]);
  if (machine->rotors[0]->position == 0)
  {
    rotateRotor(machine->rotors[1]);
    if (machine->rotors[1]->position == 0)
    {
      rotateRotor(machine->rotors[2]);
    }
  }
}