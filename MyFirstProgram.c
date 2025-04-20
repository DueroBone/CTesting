#include <stdio.h>

int main()
{
  char name[] = "My First Program";
  name[0] = 'A';
  printf("%s\n", name);
  printf("My Hello World!");
  char input[10];
  fgets(input, sizeof(input), stdin);
  return 0;
}
