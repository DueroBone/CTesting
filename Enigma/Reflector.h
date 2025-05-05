#pragma once

typedef struct
{
  int reflectorNum;
} Reflector;

Reflector generateReflector(int reflectorNum);
int runReflector(Reflector *reflector, int input);