#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rotor.h"
#include "EnigmaMachine.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Formatter.h"

EnigmaMachine *generateMachine(Rotor rotor1, Rotor rotor2, Rotor rotor3, Reflector reflector, Plugboard plugboard)
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
  machine->rotors[0].position = pos1;
  machine->rotors[1].position = pos2;
  machine->rotors[2].position = pos3;
}

void rotateRotors(EnigmaMachine *machine)
{
  rotateRotor(&machine->rotors[0]);
  if (machine->rotors[0].isNotch)
  {
    rotateRotor(&machine->rotors[1]);
    if (machine->rotors[1].isNotch)
    {
      rotateRotor(&machine->rotors[2]);
    }
  }
}

/** Input must be in the range of 0-25, modifies in-place!! */
int *runEnigmaMachine(EnigmaMachine *machine, int *input, int length)
{
  for (int i = 0; i < length; i++)
  {
    if (input[i] == -1)
    {
      continue;
    }
    input[i] = getPlugboardOutput(&machine->plugboard, input[i]);
    input[i] = getRotorOutput(&machine->rotors[0], input[i], 0);
    input[i] = getRotorOutput(&machine->rotors[1], input[i], 0);
    input[i] = getRotorOutput(&machine->rotors[2], input[i], 0);
    input[i] = runReflector(&machine->reflector, input[i]);
    input[i] = getRotorOutput(&machine->rotors[2], input[i], 1);
    input[i] = getRotorOutput(&machine->rotors[1], input[i], 1);
    input[i] = getRotorOutput(&machine->rotors[0], input[i], 1);
    input[i] = getPlugboardOutput(&machine->plugboard, input[i]);
    rotateRotors(machine);
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
  free(machine);
  machine = NULL;
}

char *machineToString(EnigmaMachine *machine)
{
  char *result = malloc(1000 * sizeof(char)); // TODO: Check how large this needs to be
  if (result == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  snprintf(result, 1000, "Rotor1: %s\nRotor2: %s\nRotor3: %s\nReflector: %d\nPlugboard: %s\n",
           rotorToString(&machine->rotors[0]),
           rotorToString(&machine->rotors[1]),
           rotorToString(&machine->rotors[2]),
           machine->reflector.reflectorNum,
           "Plugboard exists"); // TODO: Add plugboard details
  return result;
}

EnigmaMachineCompressed compressEnigmaMachine(EnigmaMachine *machine)
{
  EnigmaMachineCompressed config;
  for (int i = 0; i < 10; i++)
  {
    config.plugboard[i][0] = machine->plugboard.wiring[i][0];
    config.plugboard[i][1] = machine->plugboard.wiring[i][1];
  }
  config.rotor1 = machine->rotors[0].rotorNum;
  config.rotor2 = machine->rotors[1].rotorNum;
  config.rotor3 = machine->rotors[2].rotorNum;
  config.reflector = machine->reflector.reflectorNum;
  config.rotor1Pos = machine->rotors[0].position;
  config.rotor2Pos = machine->rotors[1].position;
  config.rotor3Pos = machine->rotors[2].position;
  return config;
}

EnigmaMachine *decompressEnigmaMachine(EnigmaMachineCompressed *config)
{
  Rotor rotor1 = generateRotor(config->rotor1, config->rotor1Pos);
  Rotor rotor2 = generateRotor(config->rotor2, config->rotor2Pos);
  Rotor rotor3 = generateRotor(config->rotor3, config->rotor3Pos);
  Reflector reflector = generateReflector(config->reflector);
  Plugboard plugboard = generateEmptyPlugboard();
  for (int i = 0; i < 10; i++)
  {
    plugboard.wiring[i][0] = config->plugboard[i][0];
    plugboard.wiring[i][1] = config->plugboard[i][1];
  }
  return generateMachine(rotor1, rotor2, rotor3, reflector, plugboard);
}