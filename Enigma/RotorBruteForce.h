#pragma once

#include "EnigmaMachine.h"
#include "Rotor.h"
#include "EngishScorer.h"

static const int numSaved = 3;

typedef struct
{
  int numResults;
  EnglishScore scores[numSaved];
} RotorBruteForceResult;

RotorBruteForceResult rotorBruteForce(EnigmaMachine *machine, int *input, int length);
char **testResults(RotorBruteForceResult result, int *textInput, int length);