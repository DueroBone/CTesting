#pragma once
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

typedef struct
{
  Rotor *rotors[3];
  Reflector *reflector;
  Plugboard *plugboard;
} EnigmaMachine;

EnigmaMachine *generateMachine(Rotor *rotor1, Rotor *rotor2, Rotor *rotor3, Reflector *reflector, Plugboard *plugboard);
void setRotorPositions(EnigmaMachine *machine, int pos1, int pos2, int pos3);
char runEnigmaMachineChar(EnigmaMachine *machine, char *input);
void freeEnigmaMachine(EnigmaMachine *machine);