#include <stdio.h>
int LOWER_START = 96;
int UPPER_START = 65;
int UPPER_LOWER_DISTANT = 32;

void uppercase(char str[])
{
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= UPPER_START && str[i] < (UPPER_START + 24))
      str[i] = str[i] - UPPER_LOWER_DISTANT;
    i++;
  }
}

void lowercase(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= UPPER_START && str[i] < (UPPER_START + 24))
      str[i] = str[i] + UPPER_LOWER_DISTANT;

    i++;
  }
}

int main(int argc, char const *argv[])
{
  char cStr[] = {'H', 'E', 'L', 'L', 'O', '\0'};
  char cStr2[] = "world\0";
  printf("%s %s \n", cStr, cStr2);
  lowercase(cStr);
  uppercase(cStr2);
  printf("%s %s \n", cStr, cStr2);
  return 0;
}
