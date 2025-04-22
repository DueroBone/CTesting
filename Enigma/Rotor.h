#pragma once

typedef struct
{
  int wirings[26];
  int position;
} Rotor;

/** Hello */
int getRotorOutput(Rotor *rotor, int input);
void setRotorOffset(Rotor *rotor, int position);
char *rotorToString(Rotor *rotor);
void rotateRotor(Rotor *rotor);