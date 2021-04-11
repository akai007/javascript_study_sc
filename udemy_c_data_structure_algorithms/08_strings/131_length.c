#include <stdio.h>

int getLength(char *str)
{
  int count = 0;
  printf("%c", str[0]);
  for (int i = 0; str[i] != '\0'; i++)
  {
    count++;
  }
  return count;
}

int main(int argc, char const *argv[])
{
  char cStr[] = {'H', 'E', 'L', 'L', 'O', 'W', '\0'};
  char *cStr2 = "WORLD\0";
  printf("%s:%d %s:%d", cStr, getLength(cStr), cStr2, getLength(cStr2));
  return 0;
}
