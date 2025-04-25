#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "EnigmaMachine.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

int main()
{
  int repeats = 10;
  double times[repeats];
  for (; repeats > 0; repeats--)
  {
    EnigmaMachine *machine = generateMachine(
        generateRotor(1, 0), // Replace with actual rotor initialization
        generateRotor(2, 0), // Replace with actual rotor initialization
        generateRotor(3, 0), // Replace with actual rotor initialization
        NULL,                // Replace with actual reflector initialization
        NULL                 // Replace with actual plugboard initialization
    );
    FILE *file = fopen("bible.txt", "r");
    if (file == NULL)
    {
      perror("Error opening file");
      return 1;
    }

    int length = 4167230;
    char *input = malloc(length * sizeof(char));
    if (fgets(input, length * sizeof(char), file) == NULL)
    {
      perror("Error reading file");
      fclose(file);
      return 1;
    }

    fclose(file);

    // printf("Input: %s\n", input);

    clock_t start_time = clock();
    char *output = runEnigmaMachineChar(machine, input);
    clock_t end_time = clock();

    // printf("Output: %s", output);
    double timeTaken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", timeTaken);
    free(input);
    free(output);
    freeEnigmaMachine(machine);
    times[repeats] = timeTaken;
  }
  double totalTime = 0;
  for (int i = 0; i < 10; i++)
  {
    totalTime += times[i];
  }
  double averageTime = totalTime / 10;
  printf("Average time taken: %f seconds\n", averageTime);
  return 0;
}