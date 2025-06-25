#pragma once

#include "EnigmaMachine.h"
#include "Rotor.h"
#include "EngishScorer.h"
#include "Settings.h"

typedef struct
{
  int numResults;
  EnglishScore scores[numSaved];
} BruteForceResult;

BruteForceResult rotorSettingBruteForce(EnigmaMachine *machine, int *input, int length);
BruteForceResult fullRotorBruteForce(Plugboard *plugboard, int *input, int length);
char **testResults(BruteForceResult result, int *textInput, int length);
BruteForceResult plugboardBruteForce(Plugboard *plugboard, int *input, int length);