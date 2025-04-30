#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rotor.h"
#include "EnigmaMachine.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Formatter.h"

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
  machine->reflector = reflector;
  machine->plugboard = plugboard;
  return machine;
}

char toUpper(char c)
{
  if (c >= 'a' && c <= 'z')
  {
    return c - ('a' - 'A');
  }
  return c;
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

/** Input must be in the range of 0-25 */
int *runEnigmaMachine(EnigmaMachine *machine, int *input, int length)
{
  // TODO
  for (int i = 0; i < length; i++)
  {
    // TODO: plugboard
    input[i] = getRotorOutput(machine->rotors[0], input[i], 0);
    input[i] = getRotorOutput(machine->rotors[1], input[i], 0);
    input[i] = getRotorOutput(machine->rotors[2], input[i], 0);
    input[i] = runReflector(machine->reflector, input[i]);
    input[i] = getRotorOutput(machine->rotors[2], input[i], 1);
    input[i] = getRotorOutput(machine->rotors[1], input[i], 1);
    input[i] = getRotorOutput(machine->rotors[0], input[i], 1);
    // TODO: plugboard
  }
  return input;
}

/** Copies the string to the heap */
char *runEnigmaMachineChar(EnigmaMachine *machine, char *input)
{
  int length = strlen(input);
  int *intInput = charArrToIntArr(input, length);
  runEnigmaMachine(machine, intInput, length);
  char *output = intArrToCharArr(intInput, length);
  free(intInput);
  return output;
}

void freeEnigmaMachine(EnigmaMachine *machine)
{
  for (int i = 0; i < 3; i++)
  {
    free(machine->rotors[i]);
  }
  free(machine->reflector);
  free(machine->plugboard);
  free(machine);
  machine = NULL;
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