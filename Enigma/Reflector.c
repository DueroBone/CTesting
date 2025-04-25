#include "Reflector.h"
#include <stdlib.h>

Reflector *generateReflector(int reflectorNum);
void freeReflector(Reflector *reflector);
int runReflector(Reflector *reflector, char input);