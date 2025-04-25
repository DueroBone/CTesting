#pragma once
#include <stdint.h>

typedef struct
{
  int position;
  uint8_t wirings[26];
  uint8_t notchPositon;
  uint8_t rotorNum;
} Rotor;

/** Hello */
int getRotorOutput(Rotor *rotor, int input);
void setRotorOffset(Rotor *rotor, int position);
char *rotorToString(Rotor *rotor);
void rotateRotor(Rotor *rotor);
Rotor *generateRotor(int rotorNum, int position);
void freeRotor(Rotor *rotor);