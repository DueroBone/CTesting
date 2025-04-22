#pragma once

typedef struct
{
  char *wiring; // The wiring of the reflector
} Reflector;

int runReflector(Reflector *reflector, char input);