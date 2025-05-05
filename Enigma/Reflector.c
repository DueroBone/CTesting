#include "Reflector.h"
#include <stdlib.h>

static const int reflectorWirings[][26] = {
    // Y R U H Q S L D P X N G O K M I E B F Z C W V J A T
    {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19},
    // F V P J I A O Y E D R Z X W G C T K U Q S B N M H L
    {5, 21, 15, 9, 8, 0, 14, 24, 4, 3, 17, 25, 23, 22, 6, 2, 19, 10, 20, 16, 18, 1, 13, 12, 7, 11},
};

Reflector generateReflector(int reflectorNum)
{
  Reflector reflector;
  reflector.reflectorNum = reflectorNum;
  return reflector;
}

int runReflector(Reflector *reflector, int input)
{
  int adjustedInput = reflectorWirings[reflector->reflectorNum][input];
  return adjustedInput;
}