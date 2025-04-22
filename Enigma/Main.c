#include <stdio.h>
#include "EnigmaMachine.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "RotorGenerator.h"

int main()
{
  EnigmaMachine *machine = generateMachine(
      generateRotor(1, 0), // Replace with actual rotor initialization
      generateRotor(2, 0), // Replace with actual rotor initialization
      generateRotor(3, 0), // Replace with actual rotor initialization
      NULL,                // Replace with actual reflector initialization
      NULL                 // Replace with actual plugboard initialization
  );

  char* output = runEnigmaMachineChar(machine, "HELLO");

  return 0;
}