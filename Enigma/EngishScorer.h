#pragma once
#include "EnigmaMachine.h"

typedef struct
{
  float score;
  EnigmaMachineCompressed config;
} EnglishScore;

EnglishScore calculateBigramScore(const int *text, int length, EnigmaMachineCompressed config);
EnglishScore calculateIncedenceScore(const int *text, int length, EnigmaMachineCompressed config);