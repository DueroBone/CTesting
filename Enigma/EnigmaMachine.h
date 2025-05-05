#pragma once
#include <stdint.h>
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

typedef struct
{
  Rotor rotors[3];
  Reflector reflector;
  Plugboard plugboard;
} EnigmaMachine;

typedef struct
{
  int8_t plugboard[10][2];
  int8_t rotor1;
  int8_t rotor2;
  int8_t rotor3;
  int8_t reflector;
  int8_t rotor1Pos;
  int8_t rotor2Pos;
  int8_t rotor3Pos;
} EnigmaMachineCompressed;

EnigmaMachine *generateMachine(Rotor rotor1, Rotor rotor2, Rotor rotor3, Reflector reflector, Plugboard plugboard);
void setRotorPositions(EnigmaMachine *machine, int pos1, int pos2, int pos3);
int *runEnigmaMachine(EnigmaMachine *machine, int *input, int length);
char *runEnigmaMachineChar(EnigmaMachine *machine, char *input);
void freeEnigmaMachine(EnigmaMachine *machine);
char *machineToString(EnigmaMachine *machine);
EnigmaMachineCompressed compressEnigmaMachine(EnigmaMachine *machine);
EnigmaMachine *decompressEnigmaMachine(EnigmaMachineCompressed *config);