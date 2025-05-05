#include "RotorBruteForce.h"
#include "EnigmaMachine.h"
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

// static const int numSaved = 10;

/** NOT THREAD SAFE, OPERATES ON SIMGLE MACHINE */
RotorBruteForceResult rotorBruteForce(EnigmaMachine *machine, int *input, int length)
{
  // Runs the machine with set plugboard configuration, all rotor positions
  RotorBruteForceResult result = {0};
  result.numResults = numSaved;
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
        BigramScore score = calculateBigramScore(output, length, compressEnigmaMachine(machine));
        int newOutput[length];
        for (int l = 0; l < length; l++)
        {
          newOutput[l] = output[l];
        }
        free(output);
        if (score.score < result.scores[numSaved - 1].score)
        {
          continue; // Skip if score is not better than the worst saved
        }
        for (int l = 0; l < numSaved; l++)
        {
          if (result.scores[l].score < score.score)
          {
            // Shift scores down
            for (int m = numSaved - 1; m > l; m--)
            {
              result.scores[m] = result.scores[m - 1];
              copyConfig(&result.scores[m].config, &result.scores[m - 1].config);
            }
            memcpy(&result.scores[l], &score, sizeof(BigramScore));
            break;
          }
        }
      }
    }
  }

  return result;
}

char **testResults(RotorBruteForceResult result, int *textInput, int length)
{
  char **results = malloc(numSaved * sizeof(char *));
  if (results == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  for (int i = 0; i < numSaved; i++)
  {
    results[i] = malloc((500 + length) * sizeof(char)); // TODO: Check how large this needs to be
    if (results[i] == NULL)
    {
      fprintf(stderr, "Memory allocation failed\n");
      return NULL;
    }

    snprintf(results[i], 500, "Score: %f\nRotor1: %d@%d\nRotor2: %d@%d\nRotor3: %d@%d\nReflector: %d\nPlugboard: %s\nOutput: %s\n",
             result.scores[i].score,
             result.scores[i].config.rotor1,
             result.scores[i].config.rotor1Pos,
             result.scores[i].config.rotor2,
             result.scores[i].config.rotor2Pos,
             result.scores[i].config.rotor3,
             result.scores[i].config.rotor3Pos,
             result.scores[i].config.reflector,
             "Plugboard TBD", // TODO: Add plugboard details
             intArrToCharArr(runEnigmaMachine(decompressEnigmaMachine(&result.scores[i].config), textInput, length), length));
  }
  return results;
}