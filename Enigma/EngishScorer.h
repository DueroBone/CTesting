#pragma once
#include "EnigmaMachine.h"

typedef struct
{
  float score;
  EnigmaMachineCompressed config;
} BigramScore;

BigramScore calculateBigramScore(const int *text, int length, EnigmaMachineCompressed config);