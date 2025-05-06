#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include "EnigmaMachine.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "EngishScorer.h"
#include "Formatter.h"
#include "RotorBruteForce.h"

int main()
{
  EnigmaMachine *machine = generateMachine(
      generateRotor(1, 0),
      generateRotor(2, 0),
      generateRotor(3, 0),
      generateReflector(0),
      generateEmptyPlugboard()
      // generatePlugboard((int[10][2]){{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}) // Example plugboard wiring
  );

  FILE *file = fopen("bible.txt", "r");
  int length = 60000;
  char *input = malloc(length * sizeof(char));
  fgets(input, length * sizeof(char), file);
  fclose(file);

  // charArrToIntArr(input, strlen(input));
  // char input[100] = "The quick brown fox jumps over the lazy dog";
  // char input[60] = "hello world";
  // printf("Enter text to encrypt: ");
  // fgets(input, sizeof(input), stdin);
  // Remove newline character from input
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n')
  {
    input[len - 1] = '\0';
    len--;
  }

  char *output = runEnigmaMachineChar(machine, input);
  printf("Encrypted text: %s\n\n", output);
  // continue;
  clock_t start_time = clock();
  RotorBruteForceResult result = rotorBruteForce(machine, charArrToIntArr(output, len), len);
  clock_t end_time = clock();
  double timeTaken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken for brute force: %f seconds\n", timeTaken);

  printf("Rotor Brute Force Results:\n");
  char **resultsText = testResults(result, charArrToIntArr(output, len), len);
  for (int i = 0; i < result.numResults; i++)
  {
    printf("Result %d: %s\n\n", i + 1, resultsText[i]);
    free(resultsText[i]);
  }
  free(resultsText);

  free(output);
  freeEnigmaMachine(machine);
  return 0;
}

int main_OLD()
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
        generateEmptyPlugboard() // Replace with actual plugboard initialization
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