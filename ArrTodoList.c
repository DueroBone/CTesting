#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Task
{
  int length;
  char *text;
};

struct TaskList
{
  struct Task **firstTask;
  int numTasks;
  int maxTasks;
};

struct Task *getTask(struct TaskList *taskList, int index)
{
  if (index < 0 || index >= taskList->numTasks)
  {
    return NULL;
  }
  struct Task *currentTask = taskList->firstTask[index];
  if (currentTask == NULL)
  {
    return NULL;
  }
  return currentTask;
}

struct Task *getLastTask(struct TaskList *taskList)
{
  return getTask(taskList, taskList->numTasks - 1);
}

int addTask(struct TaskList *taskList, const char *taskText)
{
  if (taskList->numTasks >= taskList->maxTasks)
  {
    // realloc to increase the size of the array
    struct Task **newTask = realloc(taskList->firstTask, sizeof(struct Task *) * (taskList->maxTasks * 2));
    if (newTask == NULL)
    {
      // realloc returns NULL if out of memory
      return 1;
    }
    taskList->maxTasks *= 2;
    taskList->firstTask = newTask;
  }
  taskList->numTasks++;
  taskList->firstTask[taskList->numTasks - 1] = (struct Task *)malloc(sizeof(struct Task));

  struct Task *newTask = malloc(sizeof(struct Task));
  if (newTask == NULL)
  {
    // malloc returns NULL if out of memory
    return 1;
  }
  newTask->length = strlen(taskText) + 1;
  newTask->text = (char *)malloc(sizeof(char) * (newTask->length));
  if (newTask->text == NULL)
  {
    // malloc returns NULL if out of memory
    return 1;
  }
  strcpy(newTask->text, taskText);
  taskList->firstTask[taskList->numTasks - 1] = newTask;
  return 0;
}

int printTasks(struct TaskList *taskList)
{
  struct Task *firstTask = *taskList->firstTask;
  if (firstTask == NULL)
  {
    printf("No tasks available.\n");
    return 1;
  }

  for (int i = 0; i < taskList->numTasks; i++)
  {
    struct Task *currentTask = (*taskList).firstTask[i];
    if (currentTask != NULL)
    {
      printf("%d: %s\n", (i + 1), currentTask->text);
    }
    else
    {
      printf("No task available.\n");
    }
  }
  return 0;
}

struct TaskList *generateList()
{
  struct TaskList *taskList = malloc(sizeof(struct TaskList));
  if (taskList == NULL)
  {
    // malloc returns NULL if out of memory
    return NULL;
  }
  taskList->firstTask = malloc(sizeof(struct Task *) * taskList->maxTasks);
  if (taskList->firstTask == NULL)
  {
    free(taskList);
    return NULL;
  }
  taskList->numTasks = 0;
  taskList->maxTasks = 2;
  return taskList;
}

int removeTask(struct TaskList *taskList, int index)
{
  index--;
  if (index < 0 || index >= taskList->numTasks)
  {
    return 1;
  }
  struct Task *currentTask = taskList->firstTask[index];
  if (currentTask == NULL)
  {
    return 1;
  }
  free(currentTask->text);
  free(currentTask);
  for (int i = index; i < taskList->numTasks - 1; i++)
  {
    taskList->firstTask[i] = taskList->firstTask[i + 1];
  }
  taskList->numTasks--;
  return 0;
}

int removeList(struct TaskList *taskList)
{
  for (int i = taskList->numTasks - 1; i >= 0; i--)
  {
    struct Task *currentTask = taskList->firstTask[i];
    if (currentTask != NULL)
    {
      free(currentTask->text);
      free(currentTask);
    }
  }
  free(taskList->firstTask);
  free(taskList);
  taskList = NULL;
  return 0;
}

int main()
{
  struct TaskList *taskList = generateList();
  if (taskList == NULL)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }
  printTasks(taskList);

  char input[] = "To be edited";
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';
  char input2[] = "TBD";
  addTask(taskList, "Buy groceries");
  addTask(taskList, "Clean the house");
  addTask(taskList, input);
  addTask(taskList, input2);
  printTasks(taskList);
  printf("\n");

  char toBeRemoved[3];
  fgets(toBeRemoved, 2, stdin);
  removeTask(taskList, toBeRemoved[0] - '0');
  printTasks(taskList);
  removeList(taskList);
  return 0;
}