#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Task *firstTask = NULL;

struct Task
{
  struct Task *next;
  int length;
  char text[];
};

struct Task *getLastTask()
{
  struct Task *currentTask = (struct Task *)firstTask;
  while (currentTask != NULL && currentTask->next != 0)
  {
    currentTask = (struct Task *)currentTask->next;
  }
  return currentTask;
}

int addTask(const char *taskText)
{
  struct Task *lastTask = getLastTask();
  struct Task *newTask = malloc(sizeof(struct Task) + strlen(taskText) + 1);
  newTask->next = 0;
  newTask->length = strlen(taskText);
  memcpy(newTask->text, taskText, newTask->length + 1);
  if (lastTask == NULL)
  {
    // malloc returns NULL if out of memory
    firstTask = newTask;
    return 1;
  }
  else
  {
    lastTask->next = newTask;
  }
  return 0;
}

int printTasks()
{
  struct Task *currentTask = (struct Task *)firstTask;
  while (currentTask != 0)
  {
    printf("%s\n", currentTask->text);
    currentTask = (struct Task *)currentTask->next;
  }
  return 0;
}

int main()
{
  char input[20] = "To be edited";
  fgets(input, sizeof(input), stdin);
  addTask("Buy groceries");
  addTask("Clean the house");
  addTask(input);
  printTasks();
  return 0;
}