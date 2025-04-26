#pragma once

typedef struct
{
  int reflectorNum;
} Reflector;

Reflector *generateReflector(int reflectorNum);
void freeReflector(Reflector *reflector);
int runReflector(Reflector *reflector, int input);