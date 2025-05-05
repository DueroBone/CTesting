#pragma once

/** Must have filled plugs first then empty plugs are afterwards, set to -1 */
typedef struct
{
  int wiring[10][2];
} Plugboard;

Plugboard generateEmptyPlugboard();
Plugboard generatePlugboard(int wiring[10][2]);
void freePlugboard(Plugboard *plugboard);
int getPlugboardOutput(Plugboard *plugboard, int input);