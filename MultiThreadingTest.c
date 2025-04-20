#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
// #include "ArrTodoList.c"

void *doStuff(void *arg)
{
  int *args = (int *)arg;
  int threadNumber = args[0];
  int maxNumber = args[1];
  free(args);
  printf("Thread Start: %d\n", threadNumber);
  int hello = 0;
  for (int i = 0; i < maxNumber; i++)
  {
    hello++;
  }
  printf("*Thread Done: %d\n", threadNumber);
  return NULL;
}

int main()
{
  int numThreads = 6;
  pthread_t threads[numThreads];
  int maxNumber = 2e9;
  for (int i = 0; i < numThreads; i++)
  {
    int *args = malloc(sizeof(int) * 2);
    args[0] = i;
    args[1] = maxNumber;
    pthread_create(&threads[i], NULL, doStuff, (void *)args);
  }
  printf("\nThreads Created\n\n");
  for (int i = 0; i < 10; i++)
  {
    pthread_join(threads[i], NULL);
  }
  printf("All Threads Done\n");
}