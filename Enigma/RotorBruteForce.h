#pragma once

#include "EnigmaMachine.h"
#include "Rotor.h"
#include "EngishScorer.h"
#include "Settings.h"

typedef struct
{
  int numResults;
  EnglishScore scores[numSaved];
} RotorBruteForceResult;

RotorBruteForceResult rotorSettingBruteForce(EnigmaMachine *machine, int *input, int length);
char **testResults(RotorBruteForceResult result, int *textInput, int length);