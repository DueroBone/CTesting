#pragma once

typedef struct
{
  int wirings[26];
  int offset;
} Rotor;

/** Hello */
int getRotorOutput(Rotor *rotor, int input);
void setRotorOffset(Rotor *rotor, int offset);
char *rotorToString(Rotor *rotor);