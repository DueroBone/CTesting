#include "RotorBruteForce.h"
#include "EnigmaMachine.h"
#include "Plugboard.h"
#include "Formatter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void copyConfig(EnigmaMachineCompressed *dest, EnigmaMachineCompressed *src)
{
  for (int i = 0; i < 10; i++)
  {
    dest->plugboard[i][0] = src->plugboard[i][0];
    dest->plugboard[i][1] = src->plugboard[i][1];
  }
  dest->rotor1 = src->rotor1;
  dest->rotor2 = src->rotor2;
  dest->rotor3 = src->rotor3;
  dest->reflector = src->reflector;
  dest->rotor1Pos = src->rotor1Pos;
  dest->rotor2Pos = src->rotor2Pos;
  dest->rotor3Pos = src->rotor3Pos;
}

void addScoresToResults(RotorBruteForceResult *result, EnglishScore *score)
{
  if (score->score < result->scores[numSaved - 1].score)
  {
    // continue; // Skip if score is not better than the worst saved
  }
  for (int l = 0; l < numSaved; l++)
  {
    if (result->scores[l].score < score->score)
    {
      // Shift scores down
      for (int m = numSaved - 1; m > l; m--)
      {
        result->scores[m] = result->scores[m - 1];
        copyConfig(&result->scores[m].config, &result->scores[m - 1].config);
      }
      memcpy(&result->scores[l], score, sizeof(EnglishScore));
      break;
    }
  }
}

// static const int numSaved = 10;

/** NOT THREAD SAFE, OPERATES ON SIMGLE MACHINE */
RotorBruteForceResult rotorSettingBruteForce(EnigmaMachine *machine, int *input, int length)
{
  // Runs the machine with set plugboard configuration, all rotor positions
  RotorBruteForceResult result = {0};
  result.numResults = numSaved;
  for (int i = 0; i < numSaved; i++)
  {
    result.scores[i].score = -100;
  }
  int newInput[length];
  for (int i = 0; i < length; i++)
  {
    newInput[i] = input[i];
  }

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      for (int k = 0; k < 26; k++)
      {
        setRotorPositions(machine, i, j, k);

        // copy input
        int *output = malloc(sizeof(int) * length);
        if (output == NULL)
        {
          fprintf(stderr, "Memory allocation failed\n");
          continue;
        }
        memcpy(output, input, sizeof(int) * length);
        output = runEnigmaMachine(machine, output, length);
        setRotorPositions(machine, i, j, k);
        EnglishScore score = calculateIncedenceScore(output, length, compressEnigmaMachine(machine));
        // EnglishScore score = calculateBigramScore(output, length, compressEnigmaMachine(machine));

        if (machine->rotors[0].rotorNum == 1 && machine->rotors[1].rotorNum == 2 && machine->rotors[2].rotorNum == 3 && machine->reflector.reflectorNum == 1 && machine->rotors[0].position == 0 && machine->rotors[1].position == 0 && machine->rotors[2].position == 0)
        {
          printf(" "); // Add breakpoint here
        }
        free(output);
        addScoresToResults(&result, &score);
      }
    }
  }

  return result;
}

static int factorial(int n)
{
  if (n <= 1)
    return 1;
  return n * factorial(n - 1);
}

RotorBruteForceResult fullRotorBruteForce(int *input, int length)
{
  // const int numRotors = 3;
  const int numReflectors = 2;
  const int numCombinations = 6;
  const int rotorCombinations[][3] = {
      {1, 2, 3},
      {1, 3, 2},
      {2, 1, 3},
      {2, 3, 1},
      {3, 1, 2},
      {3, 2, 1}};

  const int numToTry = numCombinations * numReflectors;
  RotorBruteForceResult resultsList[numToTry];

#pragma omp parallel for
  for (int i = 0; i < numToTry; i++)
  {
    Rotor rotor1 = generateRotor(rotorCombinations[i % numCombinations][0], 0);
    Rotor rotor2 = generateRotor(rotorCombinations[i % numCombinations][1], 0);
    Rotor rotor3 = generateRotor(rotorCombinations[i % numCombinations][2], 0);
    Reflector reflector = generateReflector(i / numCombinations);
    Plugboard plugboard = generateEmptyPlugboard(); // Assuming empty plugboard as IOC is uneffected by plugboard

    EnigmaMachine *tempMachine = generateMachine(rotor1, rotor2, rotor3, reflector, plugboard);
    RotorBruteForceResult result = rotorSettingBruteForce(tempMachine, input, length);
    freeEnigmaMachine(tempMachine);

    resultsList[i] = result;
  }

  RotorBruteForceResult combinedResult = {0};
  combinedResult.numResults = numSaved;
  for (int i = 0; i < numSaved; i++)
  {
    combinedResult.scores[i].score = -100;
  }

  for (int i = 0; i < numToTry; i++)
  {
    for (int j = 0; j < numSaved; j++)
    {
      addScoresToResults(&combinedResult, &resultsList[i].scores[j]);
    }
  }

  return combinedResult;
}

char **testResults(RotorBruteForceResult result, int *textInput, int length)
{
  char **results = malloc(numSaved * sizeof(char *));
  if (results == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  const int pretextLength = 150;
  for (int i = 0; i < numSaved; i++)
  {
    results[i] = malloc((pretextLength + length) * sizeof(char));
    if (results[i] == NULL)
    {
      fprintf(stderr, "Memory allocation failed\n");
      return NULL;
    }

    snprintf(results[i], pretextLength + length, "Score: %.12f\nRotor1: %d@%d\nRotor2: %d@%d\nRotor3: %d@%d\nReflector: %d\nPlugboard: %s\nOutput: %s\n",
             result.scores[i].score,
             result.scores[i].config.rotor1,
             result.scores[i].config.rotor1Pos,
             result.scores[i].config.rotor2,
             result.scores[i].config.rotor2Pos,
             result.scores[i].config.rotor3,
             result.scores[i].config.rotor3Pos,
             result.scores[i].config.reflector,
             compressedPlugboardToString(result.scores[i].config.plugboard),
             intArrToCharArr(runEnigmaMachine(decompressEnigmaMachine(&result.scores[i].config), textInput, length), length));
  }
  return results;
}