#include <stdio.h>

int UPPER_START = 65;
int ASCLL_SPACE = 32;

int countVowel(char * str)
{
  int count = 0;
  int i = 0;
  while (str[i] != '\0')
  {
    char strI = str[i];
    if (strI >= UPPER_START && strI < (UPPER_START + 24))
      strI = strI + 32;
    if (
      strI == 'a' ||
      strI == 'e' ||
      strI == 'i' ||
      strI == 'o' ||
      strI == 'u'
    )
    {
      count++;
    }
    
    i++;
  }
  
  return count;
}

int countWold(char * str)
{
  int count = 1;

  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == ASCLL_SPACE)
      count++;
    
    i++;
  }

  return count;
}

int main(int argc, char const *argv[])
{
  char str[] = "Hello World";
  printf("\"%s\" has %d vowels and %d wolds", str, countVowel(str), countWold(str));
  return 0;
}

