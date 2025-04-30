#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "EnigmaMachine.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

int main()
{
  clock_t Mainstart_time = clock();
  int repeats = 2000;
  double times[repeats];
  int numThreads = 5;
  omp_set_num_threads(numThreads);
#pragma omp parallel for
  for (int i = 0; i < repeats; i++)
  {
    EnigmaMachine *machine = generateMachine(
        generateRotor(1, 0),
        generateRotor(2, 0),
        generateRotor(3, 0),
        generateReflector(0),
        NULL // Replace with actual plugboard initialization
    );
    FILE *file = fopen("bible.txt", "r");
    if (file == NULL)
    {
      perror("Error opening file");
      continue;
    }

    int length = 4167230;
    char *input = malloc(length * sizeof(char));
    if (fgets(input, length * sizeof(char), file) == NULL)
    {
      perror("Error reading file");
      fclose(file);
      continue;
    }

    fclose(file);

    // input = "Hello world";

    // printf("Input: %s  ", input);

    clock_t start_time = clock();
    char *output = runEnigmaMachineChar(machine, input);
    clock_t end_time = clock();

    // printf("Output: %s  |  ", output);
    double timeTaken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    // printf("Time taken: %f seconds\n", timeTaken);
    free(input);
    free(output);
    freeEnigmaMachine(machine);
    times[i] = timeTaken;
  }
#pragma omp barrier
  double totalTime = 0;
  for (int i = 0; i < repeats; i++)
  {
    totalTime += times[i];
  }
  double averageTime = totalTime / repeats;
  printf("Average time taken: %f seconds\n", averageTime);
  printf("Finished after %f seconds\n", (double)(clock() - Mainstart_time) / CLOCKS_PER_SEC);
  return 0;
}