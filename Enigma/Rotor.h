#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  int position;
  int notchPositon;
  int rotorNum;
  bool isNotch;
  uint8_t wirings[26][2];
} Rotor;

int getRotorOutput(Rotor *rotor, int input, int isReverse);
void setRotorOffset(Rotor *rotor, int position);
char *rotorToString(Rotor *rotor);
void rotateRotor(Rotor *rotor);
Rotor generateRotor(int rotorNum, int position);
void freeRotor(Rotor *rotor);