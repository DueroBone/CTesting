#pragma once

typedef struct
{
  int wiring[26]; // The wiring of the reflector
} Reflector;

int runReflector(Reflector *reflector, char input);